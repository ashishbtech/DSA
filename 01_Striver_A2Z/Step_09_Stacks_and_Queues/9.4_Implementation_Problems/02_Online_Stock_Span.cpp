#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE: Store all prices and count backwards
// Time Complexity: O(N) per call | Space Complexity: O(N)
class StockSpannerBrute
{
private:
    vector<int> prices;

public:
    StockSpannerBrute() {}

    int next(int price)
    {
        prices.push_back(price);
        int span = 0;

        for (int i = prices.size() - 1; i >= 0; i--)
        {
            if (prices[i] <= price)
            {
                span++;
            }
            else
            {
                break;
            }
        }
        return span;
    }
};

// OPTIMAL: Monotonic Stack storing {price, accumulated_span}
// Time Complexity: Amortized O(1) per call | Space Complexity: O(N) auxiliary
class StockSpannerOptimal
{
private:
    stack<pair<int, int>> st;

public:
    StockSpannerOptimal() {}

    int next(int price)
    {
        int span = 1; // Base span includes the current day itself

        // Absorb spans of all previous consecutive days with lesser or equal prices
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }

        // Push the new price and its total absorbed span
        st.push({price, span});
        return span;
    }
};

int main()
{
    cout << "Testing Optimal Stock Spanner:\n";
    StockSpannerOptimal *spanner = new StockSpannerOptimal();

    cout << "Price 100 -> Span: " << spanner->next(100) << "\n";
    cout << "Price 80  -> Span: " << spanner->next(80) << "\n";
    cout << "Price 60  -> Span: " << spanner->next(60) << "\n";
    cout << "Price 70  -> Span: " << spanner->next(70) << "\n";
    cout << "Price 60  -> Span: " << spanner->next(60) << "\n";
    cout << "Price 75  -> Span: " << spanner->next(75) << "\n";
    cout << "Price 85  -> Span: " << spanner->next(85) << "\n";

    delete spanner;
    return 0;
}