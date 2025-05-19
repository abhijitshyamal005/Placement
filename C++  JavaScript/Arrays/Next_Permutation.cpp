/* Next Permutation
    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
    If such arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).
    The replacement must be in place and use only constant extra memory.
    Here are some examples, with input being the array representation of the permutation:
    Input: 1,2,3
    Output: 1,3,2

    Input: 3,2,1
    Output: 1,2,3

    Input: 1,1,5
    Output: 1,5,1

    Input: 1
    Output: 1

    Approach:
    1. Find the largest index i such that nums[i] < nums[i + 1]. If no such index exists, the permutation is the last permutation.
    2. Find the largest index j greater than i such that nums[i] < nums[j].
    3. Swap the value of nums[i] with that of nums[j].
    4. Reverse the sequence from nums[i + 1] up to and including the final element nums[nums.size() - 1].
    5. Return the modified array.
    Time Complexity: O(n)
    Space Complexity: O(1)

*/

// C++ implementation of Next Permutation
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size(), k, l;
        for (k = n - 2; k >= 0; k--)
        {
            if (nums[k] < nums[k + 1])
            {
                break;
            }
        }
        if (k < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            for (l = n - 1; l > k; l--)
            {
                if (nums[l] > nums[k])
                {
                    break;
                }
            }
            swap(nums[k], nums[l]);
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};

// JavaScript implementation of Next Permutation
function nextPermutation(nums)
{
    let n = nums.length;
    let k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (nums[k] < nums[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        nums.reverse();
    }
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (nums[l] > nums[k])
            {
                break;
            }
        }
        [ nums[k], nums[l] ] = [ nums[l], nums[k] ];
        nums.splice(k + 1, n - k - 1, ... nums.slice(k + 1).reverse());
    }
}