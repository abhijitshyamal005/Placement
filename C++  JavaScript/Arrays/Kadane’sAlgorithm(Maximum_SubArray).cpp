/* Kadane’s Algorithm
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
    
    A subarray is a contiguous part of an array.
    
    Example 1:
    Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.
    
    Example 2:
    Input: nums = [1]
    Output: 1
    
    Example 3:
    Input: nums = [5,4,-1,7,8]
    Output: 23
    
    Approach:
    1. Initialize two variables, maxSum and currentSum, to the first element of the array.
    2. Iterate through the array starting from the second element.
    3. For each element, update currentSum to be the maximum of the current element and the sum of currentSum and the current element.
    4. Update maxSum to be the maximum of maxSum and currentSum.
    5. Return maxSum.
    Time Complexity: O(n)
*/

// C++ implementation of Kadane's Algorithm

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0;
        int maxSum = nums[0];
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            maxSum = max(sum,maxSum);
            if(sum<0) sum =0;
        }
        return maxSum;

        
    }
};

// JavaScript implementation of Kadane's Algorithm

function maxSubArray(nums) {
    let sum = 0;
    let maxSum = nums[0];
    for (let i = 0; i < nums.length; i++) {
        sum += nums[i];
        maxSum = Math.max(sum, maxSum);
        if (sum < 0) sum = 0;
    }
    return maxSum;
}