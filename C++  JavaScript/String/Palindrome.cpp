/* check if a string is a palindrome
 * A palindrome is a string that reads the same backward as forward.
 * This function checks if the input string is a palindrome.
 example:
    * Input: "racecar"
    * Output: true
    * Input: "hello"
    * Output: false

    Approach:
    * 1. Initialize two pointers, one at the start and one at the end of the string.
    * 2. Move the pointers towards the center, comparing characters.
    * 3. Ignore non-alphanumeric characters and case differences.
 * 4. If all characters match, return true; otherwise, return false.
 * Time Complexity: O(n), where n is the length of the string.
// Space Complexity: O(1), since we are using only a constant amount of extra space.
 
*/

// c++ program to check if a string is a palindrome
class Solution {
public:
    bool isPalindrome(string s) {
    int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
}
};