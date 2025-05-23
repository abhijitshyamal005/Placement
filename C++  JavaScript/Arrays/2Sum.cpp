/* TWo Sum 

Here we solve a problem where have a array and a target value
we should be found the two index og the element
example:
    array : [2,7,11,15]
    target : 9
    output : [0,1]

    Approach:
    1. Create a map to store the value and index of the elements
    2. Iterate through the array
    3. For each element, calculate the complement (target - current element)
    4. Check if the complement exists in the map
    5. If it exists, return the indices of the current element and the complement
    6. If it doesn't exist, add the current element and its index to the map
    7. If no solution is found, return an empty vector
    Time complexity: O(n)
 
*/
// C++ solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }

        return {}; 
    }
};

// JavaScript solution

function twoSum(nums, target) {
    const numMap = new Map();

    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        if (numMap.has(complement)) {
            return [numMap.get(complement), i];
        }
        numMap.set(nums[i], i);
    }

    return []; // No solution found
}