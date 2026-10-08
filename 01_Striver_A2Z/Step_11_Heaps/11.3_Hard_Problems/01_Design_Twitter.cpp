#include <bits/stdc++.h>
using namespace std;

class Twitter
{
private:
    // Global timestamp to keep tweets chronologically ordered
    int timestamp;

    // Map userId to a vector of their tweets: pair<timestamp, tweetId>
    unordered_map<int, vector<pair<int, int>>> tweets;

    // Map userId to a set of userIds they follow
    unordered_map<int, unordered_set<int>> following;

public:
    Twitter()
    {
        timestamp = 0;
    }

    // O(1) time
    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({timestamp++, tweetId});
    }

    // O(U * 10 * log 10) time, where U is number of followees
    vector<int> getNewsFeed(int userId)
    {
        // Min Heap to keep the 10 most recent tweets.
        // Stores pair<timestamp, tweetId>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Compile a list of all users whose tweets we care about (self + followees)
        vector<int> usersToCheck;
        usersToCheck.push_back(userId);
        if (following.find(userId) != following.end())
        {
            for (int followeeId : following[userId])
            {
                usersToCheck.push_back(followeeId);
            }
        }

        // Check tweets for all relevant users
        for (int uId : usersToCheck)
        {
            if (tweets.find(uId) != tweets.end())
            {
                int numTweets = tweets[uId].size();

                // Optimization: Only look at this user's 10 most recent tweets
                for (int i = numTweets - 1; i >= max(0, numTweets - 10); i--)
                {
                    minHeap.push(tweets[uId][i]);

                    // Keep the heap size strictly at 10
                    if (minHeap.size() > 10)
                    {
                        minHeap.pop(); // Evict the oldest tweet
                    }
                }
            }
        }

        // Extract the 10 tweets from the Min Heap
        vector<int> newsFeed;
        while (!minHeap.empty())
        {
            newsFeed.push_back(minHeap.top().second);
            minHeap.pop();
        }

        // Since it's a Min Heap, the oldest of the top 10 comes out first.
        // We must reverse it so the most recent is at index 0.
        reverse(newsFeed.begin(), newsFeed.end());
        return newsFeed;
    }

    // O(1) time
    void follow(int followerId, int followeeId)
    {
        // A user shouldn't formally follow themselves in our set to avoid logical bugs
        if (followerId != followeeId)
        {
            following[followerId].insert(followeeId);
        }
    }

    // O(1) time
    void unfollow(int followerId, int followeeId)
    {
        if (following.find(followerId) != following.end())
        {
            following[followerId].erase(followeeId);
        }
    }
};

void printFeed(const vector<int> &feed)
{
    cout << "News Feed: [";
    for (int i = 0; i < feed.size(); i++)
    {
        cout << feed[i] << (i == feed.size() - 1 ? "" : ", ");
    }
    cout << "]\n";
}

int main()
{
    cout << "Initializing Twitter...\n";
    Twitter twitter;

    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);
    cout << "User 1 posts tweet 5.\n";

    // User 1's news feed should return a list with 1 tweet id -> [5].
    printFeed(twitter.getNewsFeed(1));

    // User 1 follows user 2.
    twitter.follow(1, 2);
    cout << "User 1 follows User 2.\n";

    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);
    cout << "User 2 posts tweet 6.\n";

    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet 6 was posted after tweet 5.
    printFeed(twitter.getNewsFeed(1));

    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);
    cout << "User 1 unfollows User 2.\n";

    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    printFeed(twitter.getNewsFeed(1));

    return 0;
}