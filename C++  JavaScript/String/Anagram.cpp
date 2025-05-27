/* Anagram

example 
 input: "listen", "silent"
output: true

input : "hello", "world"
output: false

Note: An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Approach:

*/

// Approach1: Using Map
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;

        for (auto& x : s) {
            mp[x]++;
        }
        for (auto& x : t) {
            mp[x]--;
        }

        for (auto& x : mp) {
            if (x.second != 0)
                return 0;
        }
        return 1;
    }
};

// Approach2: Using Sorting

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};