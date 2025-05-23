/* Matrix rotaion By 90 , 180, 270 degree
    90 degree
    example:
    input: 1 2 3
           4 5 6
           7 8 9
    output: 7 4 1
            8 5 2
            9 6 3
    180 degree
    example:
    input: 1 2 3
           4 5 6
           7 8 9
    output: 9 8 7
            6 5 4
            3 2 1
Approaches:
1. Transpose the matrix and then reverse each row.
or
2. Reverse the matrix and then transpose it.

*/
// C++ program to rotate a matrix by 90 degrees
 class Solution {
public:
    // Function to rotate matrix anticlockwise by 90 degrees
    void rotate ( vector<vector<int>> &matrix, int n) {
        // code here
        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }