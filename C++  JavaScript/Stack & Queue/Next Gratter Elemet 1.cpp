/* NGE - next greater element
there are  two arrays one The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]

Approach:
1. Create a stack to keep track of the elements for which we need to find the next greater element.
2. Create a map to store the next greater element for each element in nums2.
3. Iterate through nums2 from right to left:
   - For each element, pop elements from the stack until the top of the stack is greater than the current element.
   - If the stack is not empty, the top of the stack is the next greater element for the current element.
   - Push the current element onto the stack.
4. Iterate through nums1 and use the map to get the next greater element for each element in nums1.
5. Return the results as an array.
time complexity: O(n)
space complexity: O(n)
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> ngeMap; // Map to store next greater elements

        // Iterate through nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop(); // Pop elements that are less than or equal to the current element
            }
            if (!st.empty()) {
                ngeMap[nums2[i]] = st.top(); // The top of the stack is the next greater element
            } else {
                ngeMap[nums2[i]] = -1; // No greater element found
            }
            st.push(nums2[i]); // Push the current element onto the stack
        }

        // Prepare the result for nums1 using the map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(ngeMap[num]);
        }

        return result;
    }
};