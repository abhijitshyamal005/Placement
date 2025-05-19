/* Intersection of two arrays
 * Given two arrays, find the intersection of the two arrays.
 * The intersection is the set of elements that are common to both arrays.
 * 
 * Example:
 * Input: arr1 = [1, 2, 2, 1], arr2 = [2, 2]
 * Output: [2]
 * 
 * Input: arr1 = [4, 9, 5], arr2 = [9, 4, 9, 8, 4]
 * Output: [9, 4]
 * 
 * Note:
 * The result can be returned in any order.
 Approch:
    * 1. Use a hash set to store the elements of the first array.
    * 2. Iterate through the second array and check if each element is in the hash set.
    * 3. If it is, add it to the result array.
    * 4. Return the result array.  
    * 
Approch2:
    * 1. using Map
    * 2. Iterate through the first array and store the elements in a map with their count.
    * 3. Iterate through the second array and check if each element is in the map.
    * 4. If it is, add it to the result array and decrement the count in the map.
    * 5. Return the result array.
    time complexity is O(n) and space complexity is O(n). 
*/

// C++ implementation

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result;
        
        for (int num : nums2) {
            if (set1.count(num)) {
                result.insert(num);
            }
        }
        
        return vector<int>(result.begin(), result.end());
    }
};
