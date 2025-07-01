/* Sieve of Eratosthenes
This code implements the Sieve of Eratosthenes algorithm to find all prime numbers up to a given limit.
 exaple: 
Input: n = 30
Output: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29

*/

class Solution {
public: 
    vector<int> sieveOfEratosthenes(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;

        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }

        return primes;
    }
};