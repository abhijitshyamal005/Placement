// Find LCM of two numbers using GCD

class Solution {
public:
    // Function to return LCM of two numbers
    long long int findLCM(long long int a, long long int b) {
        // Calculate GCD using Euclidean algorithm
        long long int gcd = findGCD(a, b);
        // LCM formula: (a * b) / GCD(a, b)
        return (a / gcd) * b; // To prevent overflow
    }


    // Number of Subarrays With LCM Equal to K

class Solution {
public:
   int subarrayLCM(vector<int>& nums, int k) {
    int cnt = 0;
    for (int i = 0; i < size(nums); i++)
    {
        int currLcm = 1;
        for (int j = i; j < size(nums); j++)
        {
            currLcm = lcm(currLcm, nums[j]);
            if (currLcm == k) cnt++;
            if (currLcm > k) break;
        }
    }
    return cnt; 
}
};