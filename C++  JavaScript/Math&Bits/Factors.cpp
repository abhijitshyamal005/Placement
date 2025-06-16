#include <iostream>
#include <vector>

class Factors {
public:
    // Function to return all factors of n
    static std::vector<int> getFactors(int n) {
        std::vector<int> factors;
        for (int i = 1; i <= n; ++i) {
            if (n % i == 0) {
                factors.push_back(i);
            }
        }
        return factors;
    }

    // Function to return all prime factors of n
    static std::vector<int> getPrimeFactors(int n) {
        std::vector<int> primeFactors;
        for (int i = 2; i <= n; ++i) {
            while (n % i == 0) {
                primeFactors.push_back(i);
                n /= i;
            }
        }
        return primeFactors;
    }

    // Function to return all unique prime factors of n in sorted order
    static std::vector<int> getUniqueSortedPrimeFactors(int n) {
        std::set<int> uniquePrimeFactors(getPrimeFactors(n).begin(), getPrimeFactors(n).end());
        return std::vector<int>(uniquePrimeFactors.begin(), uniquePrimeFactors.end());
    }
};

// k th factor of n
class KthFactor {
public:
    // Function to return the k-th factor of n
    static int getKthFactor(int n, int k) {
        std::vector<int> factors = Factors::getFactors(n);
        if (k <= 0 || k > factors.size()) {
            return -1; // Return -1 if k is out of bounds
        }
        return factors[k - 1]; // k is 1-based index
    }
};

// Distinct prime factors product of an array
class DistinctPrimeFactorsProduct {
public:
    // Function to return the product of distinct prime factors of an array
    static long long getDistinctPrimeFactorsProduct(const std::vector<int>& arr) {
        std::set<int> distinctPrimes;
        for (int num : arr) {
            std::vector<int> primeFactors = Factors::getUniqueSortedPrimeFactors(num);
            distinctPrimes.insert(primeFactors.begin(), primeFactors.end());
        }
        
        long long product = 1;
        for (int prime : distinctPrimes) {
            product *= prime;
        }
        return product;
    }
};