/*  Dutch National Flag Algorithm / DNF Sort
    Problem: Given an array containing 0s, 1s, and 2s, sort the array in a single pass.
    Input: [2, 0, 2, 1, 1, 0]
    Output: [0, 0, 1, 1, 2, 2]
    Approach:
    1. Initialize three pointers: low, mid, and high.
    2. low =0, mid = 0, high = n-1
    3. running loop while mid <= high
    4. if arr[mid] == 0, swap (arr[low] , arr[mid]), low++, mid++
    5. if arr[mid] == 1, mid++
    6. else swap (arr[mid] , arr[high]), high--
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

// C++ code

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
