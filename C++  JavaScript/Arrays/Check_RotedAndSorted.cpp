/*
 Here we check if an array is sorted and rotated.
    The array is sorted and rotated if it is sorted in ascending order and then rotated.
     for  example,
     there will be 4 conditions for the array to be sorted and rotated.
        1. The array is sorted in ascending order and then rotated. [1,2,3,4,5,6,7]
        its return one pare where [i-1] > [i] or [n-1] > [0] , here  7>1
        2. the array [ 4,5,6,7,1,2,3] is sorted and rotated.
           its return one pare where [i-1] > [i] or [n-1] > [0] , here 7 > 1
        3. the array contain same element [ 1,1,1,1,1,1,1] is sorted and rotated.
           its not return any pare where [i-1] > [i] or [n-1] > [0]
        4 array [ 3,4,5,1,2,6,7] is not sorted and rotated.
           because ite return two pare where [i-1] > [i] or [n-1] > [0] , here 5>1 and 7>3

           ** conclusion **  it is sorted and rotated if it return only one pare or no pare  where [i-1] > [i] or [n-1] > [0]
           countPare <=1
*/

// c++ Code

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
                count++;
        }
        if (nums[n - 1] > nums[0])
            count++;
        return count <= 1;
    }
};

// JavaScript Code

function check(nums)
{
    let count = 0;
    const n = nums.length;
    for (let i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
            count++;
    }
    if (nums[n - 1] > nums[0])
        count++;
    return count <= 1;
}