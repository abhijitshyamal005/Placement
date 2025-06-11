/* NSE (Next Sort Element) is a problem where we need to find the next greater element for each element in an array.
example:
Input: [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]

explanation:
 for 4 next smaller element is 2
for 8 next smaller element is 5
for 5 next smaller element is 2
for 2 next smaller element is -1
for 25 next smaller element is -1

Approach:
We can use a stack to keep track of the elements for which we haven't found the next smaller element yet.

*/

class solution {
public:
    vector<int> nextSortElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                result[s.top()] = arr[i];
                s.pop();
            }
            s.push(i);
        }

        return result;
    }
};
