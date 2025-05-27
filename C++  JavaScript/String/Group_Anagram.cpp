/* group_anagrams.cpp
 * This program groups anagrams from a list of strings.
 * It uses a hash map to store sorted strings as keys and their anagrams as values.
 
 exxample input: ["eat", "tea", "tan", "ate", "nat", "bat"]
 output: [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
 
 example input: ["", "b"]
 output: [[""], ["b"]]

Approach:
 * 1. Create a hash map to store sorted strings as keys.
 * 2. For each string, sort it and use it as a key in the hash map.
 * 3. Append the original string to the list of anagrams for that key.
 * 4. Finally, return the values of the hash map as a vector of vectors.
 *
 * Time Complexity: O(n * k log k), where n is the number of strings and k is the maximum length of a string.
 * Space Complexity: O(n * k), where n is the number of strings and k is the maximum length of a string.

*/

//c++ code
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string ,vector<string>>mp;

        for(auto it : strs)
        {
            string temp = it;
            sort(it.begin(),it.end());
            mp[it].push_back(temp);
        }

        vector<vector<string>>ans;

        for(auto x : mp)
        {
            ans.push_back(x.second);
        }
        return ans;
        
    }
};