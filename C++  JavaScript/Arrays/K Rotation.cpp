/* Rotation of an array
   Given an array, rotate the array to the right by k steps, where k is non-negative.
   Example:
   Input: nums = [1,2,3,4,5,6,7], k = 3
   Output: [5,6,7,1,2,3,4]
   Explanation:
 Approach: 1
   we assign the  nums[i] to nums[(i+k)%n] where n is the size of the array.
   This will give us the rotated array.
    we create a new array of size n and assign the values to it for avoiding the overwriting of the original array.
*/

// C++ code

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        vector<int>temp(nums.size());     // create a new array of size n to avoid overwriting the original array
        for (int i=0;i<nums.size();i++)
        {
            temp[(i+k)%nums.size()]=nums[i];
        }
        nums = temp ;
        
    }
};


// JavaScript code



var rotate = function(nums, k) {
    let n = nums.length;
    k = k % n; // in case k is greater than n
    let temp = new Array(n); // create a new array of size n to avoid overwriting the original array
    for (let i = 0; i < n; i++) {
        temp[(i + k) % n] = nums[i];
    }
    for (let i = 0; i < n; i++) {
        nums[i] = temp[i];
    }
};