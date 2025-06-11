/* Largest rectangle in histogram
here we are given an array of integers representing the heights of bars in a histogram.
The task is to find the area of the largest rectangle that can be formed using these bars.
example:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The largest rectangle can be formed using the heights 5 and 6, with a width of 2, resulting in an area of 10.

Approach:
// 1. Use a stack to keep track of the indices of the histogram bars.


*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int maxArea = 0;
        heights.push_back(0); // Add a sentinel value to pop all remaining bars

        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, h * w);
            }
            s.push(i);
        }

        return maxArea;
    }
};