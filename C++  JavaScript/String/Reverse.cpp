/* Here we reverse a String
 example: 
      input: "Hello World"
    output: "dlroW olleH"

    input: "C++ Programming"
    output: "gnimmargorP ++C"

   Approach:
1. Use two pointers, one at the start and one at the end of the string.
2. Swap the characters at these two pointers.
*/

// 

// c++ code 
 class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i=0;i<s.size()/2;i++)
        {
            swap(s[i],s[s.size()-1-i]);
        }
        
    }
};