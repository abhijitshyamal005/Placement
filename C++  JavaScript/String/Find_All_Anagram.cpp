/* Find All Anagrams in a String

example: Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
input: s = "cbaebabacd", p = "abc"
output: [0, 6]

input: s = "abab", p = "ab"
output: [0, 1, 2]

Approach:
// 1. Use a sliding window approach to maintain a window of size equal to the length of p.
// 2. Use two frequency arrays to count the characters in p and the current window in s.
// 3. Compare the two frequency arrays to check if they are equal.
// 4. If they are equal, add the starting index of the window to the result.
// 5. Slide the window by removing the character going out of the window and adding the new character coming into the window.
// 6. Continue this until the end of the string s.
// Time Complexity: O(n), where n is the length of the string s.
// Space Complexity: O(1), since the frequency array size is constant (26 for lowercase English letters).
*/

// c++ code
 class Solution {
 public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;

        vector<int> pCount(26, 0), sCount(26, 0);
        
        // Count frequency of characters in p
        for (char c : p) {
            pCount[c - 'a']++;
        }

        // Initial window in s
        for (int i = 0; i < p.size(); i++) {
            sCount[s[i] - 'a']++;
        }

        // Check the first window
        if (sCount == pCount) {
            result.push_back(0);
        }

        // Slide the window
        for (int i = p.size(); i < s.size(); i++) {
            sCount[s[i] - 'a']++; // Add new character to the window
            sCount[s[i - p.size()] - 'a']--; // Remove the character going out of the window
            
            if (sCount == pCount) {
                result.push_back(i - p.size() + 1);
            }
        }

        return result;
    }