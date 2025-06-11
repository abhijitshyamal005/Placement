/* stock span problem
here we are given an array of stock prices and we need to find the span of each stock price.
there are two class
1. StockSpanner: This class is used to find the span of each stock price.
2. StockSpanner::next(int price): This function is used to find the span of the stock price.
example:
class StockSpanner {
public:
    StockSpanner() {
        // constructor
    }

    int next(int price) {
        // function to find the span of the stock price
        // return the span of the stock price
    }
};
input:
["StockSpanner", "next", "next", "next", "next"]
[[], [100], [80], [60], [70]]
// output: [null, 1, 1, 1, 2]

explanation:
// The first stock price is 100, so the span is 1.
// The second stock price is 80, so the span is 1.
// The third stock price is 60, so the span is 1.
// The fourth stock price is 70, so the span is 2 because it is greater than the previous stock price 60.
// The next stock price is 60, so the span is 1 because it is less than the previous stock price 70.

*/

class StockSpanner {
public:
    stack<pair<int, int>> s; // stack to store the price and its span

    StockSpanner() {
        // constructor
    }

    int next(int price) {
        int span = 1; // initialize span to 1
        while (!s.empty() && s.top().first <= price) { // pop elements from stack until we find a greater price
            span += s.top().second; // add the span of the popped element to the current span
            s.pop(); // pop the element from the stack
        }
        s.push({price, span}); // push the current price and its span to the stack
        return span; // return the span of the current stock price
    }
};