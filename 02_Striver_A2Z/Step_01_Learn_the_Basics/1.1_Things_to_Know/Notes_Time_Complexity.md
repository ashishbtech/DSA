# Big-O Time & Space Complexity

## 🧠 Core Rules of Big-O
1. **Worst-Case Scenario:** Always compute complexity for the worst possible input.
2. **Drop Constants:** `O(2N)` becomes `O(N)`. `O(N/2)` becomes `O(N)`. 
3. **Drop Non-Dominant Terms:** `O(N^2 + N)` becomes `O(N^2)` because as N approaches infinity, the `N^2` term completely overshadows the `N` term.

## ⏱️ Common Complexities (Fastest to Slowest)
* **O(1) Constant Time:** Array lookups `arr[i]`, basic math operations.
* **O(log N) Logarithmic Time:** Binary Search (dividing the search space in half).
* **O(N) Linear Time:** Single `for` or `while` loop traversing an array.
* **O(N log N) Linearithmic Time:** Optimal sorting algorithms like Merge Sort and Quick Sort.
* **O(N^2) Quadratic Time:** Nested loops (e.g., Bubble Sort, checking all pairs).
* **O(2^N) Exponential Time:** Unoptimized recursion (e.g., basic Fibonacci).

## 💾 Space Complexity
Space complexity is strictly about **Extra Space / Auxiliary Space**. 
If a problem gives you an array of size `N`, and you just use a few integer variables (like `sum` or `count`), your space complexity is `O(1)`. If you create a brand new array of size `N` to solve the problem, your space complexity is `O(N)`.