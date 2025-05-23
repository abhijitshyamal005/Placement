/* Moore’s Voting Algorithm
    Given an array of n elements, find the majority element in the array. The majority element is the element that appears more than n/2 times in the array.

    Example:
    Input: [3, 2, 3]
    Output: 3

    Input: [2, 2, 1, 1, 1, 2, 2]
    Output: 2

    Note:
    You may assume that the majority element always exists in the array.
    Approach:
    1. let MagorityElement = 0 , count = 0
    2. Iterate through the array
     2.a. if count == 0, set MajorityElement = arr[i];
     2.b. if arr[i] == MajorityElement, count++;
     2.c. else count--;
    3. return MajorityElement;
    Time Complexity: O(n)
    Space Complexity: O(1)
*/

// C++ code

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me =0;
        int count =0;
        for( int i : nums)
        {
            if(count == 0)
            {
                me = i;
            }
            if(i== me)
            {
                count++;
            }else{
                count --;
            }
        }
        return me;
    }
};