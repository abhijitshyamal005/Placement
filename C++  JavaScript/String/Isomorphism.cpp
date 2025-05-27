/* isomorphism
 example:
 input: "egg", "add"
 output: true

 input: "foo", "bar"
 output: false

 Note: Two strings are isomorphic if the characters in one string can be replaced to get the other string.
// Each character in the first string can map to exactly one character in the second string, and vice versa.
// No two characters may map to the same character, but a character may map to itself.  
Approach:
 1.map each character in the first string to a character in the second string.
 2.map each character in the second string to a character in the first string.
    3.check if the mappings are consistent.
    4.return true if they are consistent, otherwise return false.
    5. use two hash maps to store the mappings.
    6. iterate through the characters of both strings simultaneously.
    

 Time Complexity: O(n), where n is the length of the strings.
 Space Complexity: O(1), since the hash maps will have at most 26 entries for lowercase English letters.
*/

// c++ implementation

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map1[128]={};
        char map2[128]={};
        for(int i=0;i<s.size();++i){
            if(map1[s[i]]==0 && map2[t[i]]==0){
                map1[s[i]]=t[i];
                map2[t[i]]=s[i];
            }
            else if (map1[s[i]]!=t[i] || map2[t[i]]!=s[i]) return false;
        }
        return true;
    }
};