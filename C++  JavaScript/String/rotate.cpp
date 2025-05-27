/* Rotation of a string in C++
example: Rotate a string to the left by k characters
input: "abcdef", k = 2
output: "cdefab"

input: "abcdef", k = 4
output: "efabcd"

approach: 
1. Calculate the effective rotation by taking k modulo the length of the string.
2
*/

// C++ code
class Solution {
public:
    string rotateString(string s, int k) {
        int n = s.size();
        k = k % n; // in case k is greater than n
        return s.substr(k) + s.substr(0, k);
    }
};

