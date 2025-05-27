/* KMP Algorithm for Longest Happy Substring

Example:
input: "ababcabcabababd"
output: "ababab"

input: "aabbccddeeffgghh"
output: "aabbccddeeffgghh"
Note: The longest happy substring is defined as a substring that contains at least one 
character that appears more than once, and no character appears more than twice.

Approach:
1. Use the KMP algorithm to find the longest prefix which is also a suffix.
2. Iterate through the string and build the longest prefix array.
3. Return the substring corresponding to the longest prefix which is also a suffix.


*/

// c++ approach

class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int> lps(n,0);
        int len=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                    i--;
                }
                else{
                    lps[i]=0;
                }
            }
        }
        // cout<<lps[n-1];
        return s.substr(0,lps[n-1]);
    }
};
