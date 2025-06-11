/* Next Greater Element II
 * This code finds the next greater element for each element in a circular array.
 * It uses a stack to keep track of indices and iterates through the array twice
 * to handle the circular nature of the problem.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 example:
    * Input: [1, 2, 1]
    * Output: [2, -1, 2]
    
    approach:
    * 1. Initialize a stack to keep track of indices.
    * 2. Iterate through the array twice to handle the circular nature.
    * 3. For each element, pop from the stack until the current element is greater than the element at the index stored in the stack.
    * 4. If the stack is not empty, set the next greater element for the index at the top of the stack.
    * 5. Push the current index onto the stack.
    * 6. If the stack is empty, set the next greater element to -1.
    * 7. Return the result array containing the next greater elements.
    * 
*/

class solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> s;

        for (int i = 0; i < 2 * n; ++i) {
            int index = i % n;
            while (!s.empty() && nums[s.top()] < nums[index]) {
                result[s.top()] = nums[index];
                s.pop();
            }
            if (i < n) {
                s.push(index);
            }
        }

        return result;
    }
};