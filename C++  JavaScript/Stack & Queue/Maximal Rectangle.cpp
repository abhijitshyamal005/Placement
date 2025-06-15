/* Maximim rectangle in a binary matrix
 * Given a binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 * 
 * Example:
 * Input:
 * [
 *   ["1","0","1","0","0"],
 *   ["1","0","1","1","1"],
 *   ["1","1","1","1","1"],
 *   ["1","0","0","1","0"]
 * ]
 * Output: 6
 * Explanation: The maximal rectangle is shown in the above picture.
 * Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix.
 * Space Complexity: O(n), where n is the number of columns in the matrix.
 Approach:
 1. Use a histogram approach where each row is treated as the base of a histogram.
 2. For each row, calculate the height of the histogram by counting consecutive 1's.
 3, Use a stack to calculate the maximum area of the rectangle that can be formed with the histogram heights.
 4. Return the maximum area found.
 5. The algorithm iterates through each row and uses a stack to efficiently calculate the maximum area for each histogram representation of the rows.
*/


  class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        heights.push_back(0); // Add a sentinel value to pop all remaining bars
        int maxArea = 0, n = heights.size();

        for (int i = 0; i < n; ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                int h = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            s.push(i);
        }
        
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size(), n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }