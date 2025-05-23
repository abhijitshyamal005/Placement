/* Pascal's Triangle
   Given an integer numRows, return the first numRows of Pascal's triangle.
   In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
   [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
   Example:
   Input: numRows = 5
   Output: [
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
   Constraints:
   1 <= numRows <= 30

   Approach:
    1. Create a vector of vectors to store the triangle.
    2. Initialize the first row with 1.
    3. For each row from 1 to numRows - 1, create a new row.
    4. The first and last elements of each row are always 1.
    5. For each element in the row, calculate the value as the sum of the two elements above it.
    6. Add the new row to the triangle.
    7. Return the triangle.
    8. Time Complexity: O(numRows^2)
    9. Space Complexity: O(numRows^2)


   */

// c++ code

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        vector<int> prev;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> current(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                current[j] = prev[j - 1] + prev[j];
            }
            result.push_back(current);
            prev = current;
        }
        return result;
    }
};

const result = [];
let prev = [];

for (let i = 0; i < numRows; i++)
{
    const current = new Array(i + 1).fill(1);

    for (let j = 1; j < i; j++)
    {
        current[j] = prev[j - 1] + prev[j];
    }
    result.push(current);
    prev = current;
}
return result;
}
