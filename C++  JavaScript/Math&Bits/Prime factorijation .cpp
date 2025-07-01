/* prime factorization 
here we use the sieve of Eratosthenes to find all prime numbers up to a certain limit
input: a number n
output: all prime factors of n


*/
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int>s;
        int a = 0;
        int n;
       
        while(a<nums.size()){
            n = nums[a];
        for(int i = 2;i<=n;i++){
            while(n%i==0){
                n/=i;
                s.insert(i);
            }
        }
        a++;
    }
    return s.size();
    }
};

    // Example usage
    // int main() {
    //     Solution sol;
    //     vector<int> nums = {12, 15, 18};
    //     cout << sol.distinctPrimeFactors(nums) << endl; // Output: 3 (2, 3, 5)
    //     return 0;
    // }
};