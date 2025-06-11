/* Trapping Rainwater
 * 
 * Given an array of non-negative integers representing the height of bars in a histogram,
 * compute how much water can be trapped after raining.
 * 
 * Example:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The water trapped is represented by the blue area in the diagram.
 * 
 * Approach:
 * Use two pointers to calculate the maximum height to the left and right of each bar,
 * and then compute the water trapped at each index.
 * * Time Complexity: O(n)
 * * Space Complexity: O(n)
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];

        // Fill left max array
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        // Fill right max array
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        // Calculate trapped water
        int waterTrapped = 0;
        for (int i = 0; i < n; i++) {
            waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
        }

        return waterTrapped;
    }
};