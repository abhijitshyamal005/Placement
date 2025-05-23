/* Hare we find the target value are have in the matrix ;
example:
 input : 1  5 9
         10 11 13
         12 13 15
         target = 13
output = true
input : 1  5 9
         10 11 13
         12 13 15
         target = 14
output = false
psudeocode:
*/

//c++ code
#include <iostream>
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(),
			cols = matrix[0].size(),
            row = 0, col = cols - 1;
			
        while (row < rows && col > -1) {
            int cur = matrix[row][col];
            if (cur == target) return true;
            if (target > cur) row++;
            else col--;
        }
        
        return false;
    }
};