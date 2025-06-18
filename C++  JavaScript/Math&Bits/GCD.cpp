// Find GCD of two numbers
class GCD {
public:
    // Function to return the GCD of two numbers using the Euclidean algorithm
    static int getGCD(int a, int b) {
        if (b == 0) {
            return a; // Base case: if b is 0, return a
        }
        return getGCD(b, a % b); // Recursive case: call with b and remainder of a divided by b
    }
};

// Find GCD of an array of numbers
class Solution {
public:
 int GCD(int a, int b){
    if(b==0) return a;
    return GCD(b,a%b);
 }

public:
    int findGCD(vector<int>& nums) {
        if (nums.empty()) return 0;
        int min = *min_element(nums.begin(),nums.end());
        int max = *max_element(nums.begin(),nums.end());
        return GCD(min,max);



    }
};