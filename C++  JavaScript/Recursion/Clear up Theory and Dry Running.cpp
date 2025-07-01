/* Clear up Theory and Dry Running
    This code is a simple demonstration of recursion in C++.
    It includes a function to calculate the factorial of a number
    using recursion and a main function to test it.
    example:
    Input: n = 5
    Output: 120


*/
class FactorialCalculator {
public:
    // Function to calculate factorial using recursion
    static int factorial(int n) {
        if (n <= 1) {
            return 1; // Base case: factorial of 0 or 1 is 1
        }
        return n * factorial(n - 1); // Recursive case
    }
};

// fibonacci function
class FibonacciCalculator {
public:
    // Function to calculate nth Fibonacci number using recursion
    static int fibonacci(int n) {
        if (n <= 1) {
            return n; // Base case: fib(0) = 0, fib(1) = 1
        }
        return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
    }
};


// reverse a string using recursion
class solution {
    public:
     void reverseString( vector<char>&s){
        if(s.size() <= 1) {
            return; // Base case: if the string is empty or has one character, do nothing
        }
        char temp = s[0]; // Store the first character
        s.erase(s.begin()); // Remove the first character
        reverseString(s); // Recursively reverse the remaining string
        s.push_back(temp); // Append the stored character to the end of the string
     }