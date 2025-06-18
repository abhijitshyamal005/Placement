// power of a number    

// example: n = 2.000 , m= 10
// output: 1024.000000

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        long N = n; 
        if (N < 0) {
            N = -N;
            x = 1.0 / x;
        }
        if (N % 2 == 0) return myPow(x * x, N / 2);
        else return x * myPow(x, N - 1);
    }
};

// is it power of two 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};