/* Union of Two Arrays
   Given two arrays, the task is to find union between these two arrays.
   Union of the two arrays can be defined as the set containing distinct elements from both arrays.
   For example, if the input arrays are:
   arr1[] = {1, 2, 3, 4, 5}
   arr2[] = {1, 2, 3}
   The output should be:
   Union = {1, 2, 3, 4, 5}

   Approach:
    1. Create a set to store the union of the two arrays.
    2. Insert all elements of the first array into the set.
    3. Insert all elements of the second array into the set.
    4. The set will automatically handle duplicates, so the union will only contain distinct elements.
    5. Convert the set back to an array and return it.
    time complexity: O(n + m) where n and m are the sizes of the two arrays.
*/

// C++ program to find union of two arrays

class Solution {
public:

    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        // Create a set to store the union of the two arrays
        unordered_set<int> s;

        // Insert all elements of the first array into the set
        while(n) s.insert(arr1[--n]);   

        // Insert all elements of the second array into the set
        while(m) s.insert(arr2[--m]);       

        // Convert the set back to an array and return it
        vector<int> result(s.begin(), s.end());
        return result;
    }
};

// JavaScript program to find union of two arrays
function findUnion(arr1, arr2) {
    // Create a set to store the union of the two arrays
    const s = new Set();

    // Insert all elements of the first array into the set
    for (let i = 0; i < arr1.length; i++) {
        s.add(arr1[i]);
    }

    // Insert all elements of the second array into the set
    for (let i = 0; i < arr2.length; i++) {
        s.add(arr2[i]);
    }

    // Convert the set back to an array and return it
    return Array.from(s);
}