/* Three Sum Problem
   Given an array of integers, find all unique triplets (a, b, c) such that a + b + c = 0.
   Note: The solution set must not contain duplicate triplets.
   Example:
   Input: nums = [-1, 0, 1, 2, -1, -4]
   Output: [[-1, -1, 2], [-1, 0, 1]]

   Approach:
    1. Sort the array.
    2. Iterate through the array, and for each element, use two pointers to find pairs that sum to the negative of the current element.
    3. Skip duplicates to avoid duplicate triplets.
    4. Return the list of unique triplets.
    Complexity:
    - Time Complexity: O(n^2), where n is the number of elements in the array.
    - Space Complexity: O(1), since we are using a constant amount of space for the pointers and the result list.
Approch2:
 using hash map
    1. Create a hash map to store the frequency of each number in the array.
    2. Iterate through the array and for each element, check if there are two other elements that sum to the negative of the current element.
    3. If such a pair is found, add it to the result list.
    4. Skip duplicates to avoid duplicate triplets.
    5. Return the list of unique triplets.
    Complexity:
     - Time Complexity: O(n^2), where n is the number of elements in the array.
     - Space Complexity: O(n), since we are using a hash map to store the frequency of each number.
*/

// c++ implementation

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
                    while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return result;
    }
};