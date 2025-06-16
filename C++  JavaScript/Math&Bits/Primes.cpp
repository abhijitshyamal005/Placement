/* prime
 question1: check if a number is prime
 question2: find all prime numbers up to a given number
    question3: find the nth prime number

    Approach:
    1. To check if a number is prime, iterate from 2 to the square root of the number and check for divisibility.
    2. To find all prime numbers up to a given number, use the Sieve of Eratosthenes algorithm.
    3. To find the nth prime number, generate prime numbers using the Sieve of Eratosthenes until the nth prime is found.
*/

// C++ code to check if a number is prime

class Solution {
public:
    // Function to check if a number is prime
    bool isPrime(int n) {
        if (n <= 1) return false; // 0 and 1 are not prime numbers
        if (n <= 3) return true; // 2 and 3 are prime numbers
        if (n % 2 == 0 || n % 3 == 0) return false; // eliminate multiples of 2 and 3

        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false; // check for factors
        }
        return true;
    }

    // Function to find all prime numbers up to a given number using Sieve of Eratosthenes
    vector<int> sieveOfEratosthenes(int limit) {
        vector<bool> isPrime(limit + 1, true);
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

        for (int p = 2; p * p <= limit; ++p) {
            if (isPrime[p]) {
                for (int multiple = p * p; multiple <= limit; multiple += p) {
                    isPrime[multiple] = false; // mark multiples as non-prime
                }
            }
        }

        vector<int> primes;
        for (int i = 2; i <= limit; ++i) {
            if (isPrime[i]) {
                primes.push_back(i); // collect all prime numbers
            }
        }
        return primes;
    }

    // Function to find the nth prime number
    int nthPrime(int n) {
        int count = 0, num = 1;
        while (count < n) {
            num++;
            if (isPrime(num)) {
                count++;
            }
        }
        return num;
    }
};

// prime count
int countPrimes(int n) {
    if (n < 2) return 0; // no primes less than 2
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (int p = 2; p * p <= n; ++p) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                isPrime[multiple] = false; // mark multiples as non-prime
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) count++; // count all prime numbers
    }
    return count;
}