/* Spiral Traversal
    Given a 2D matrix, return all elements of the matrix in spiral order.
    
    Example:
    Input:
    [
      [ 1, 2, 3 ],
      [ 4, 5, 6 ],
      [ 7, 8, 9 ]
    ]
    Output: [1, 2, 3, 6, 9, 8, 7, 4, 5]
    Explanation: The elements of the matrix are traversed in the following order:
    1 -> 2 -> 3 -> 6 -> 9 -> 8 -> 7 -> 4 -> 5
    pseudo code:
    1. Initialize four pointers: top, bottom, left, right.
    2. top = 0, bottom = n - 1, left = 0, right = m - 1 where n = number of rows and m = number of columns.
    3. while (top <= bottom && left <= right):
        a.
        Traverse from left to right along the top row, incrementing top.
        b.
        Traverse from top to bottom along the right column, decrementing right.
        c.
        If there are remaining rows, traverse from right to left along the bottom row, decrementing bottom.
        d.
        If there are remaining columns, traverse from bottom to top along the left column, incrementing left.
    4. Repeat until all elements are traversed.
    5. Return the result.
    Complexity Analysis:
    Time Complexity: O(n * m), where n is the number of rows and m is the number of columns in the matrix.
    Space Complexity: O(1), as we are using only a constant amount of space for the pointers and the result array. 
*/

// C++ implementation of Spiral Traversal

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        vector<int> ans;

        while (top <= bottom && left <= right) {
            // Traverse from left to right
            for (int j = left; j <= right; j++)
                ans.push_back(matrix[top][j]);
            top++;

            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            // Ensure we haven't crossed boundaries before moving further
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    ans.push_back(matrix[bottom][j]);
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};
