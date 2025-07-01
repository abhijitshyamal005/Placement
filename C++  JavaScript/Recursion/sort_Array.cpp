/* using recursion to sort an array in 

Approch:
1. Base Case: If the array has one or zero elements, it is already sorted.
2. Recursive Case:
   - Remove the last element from the array.
   - Recursively sort the remaining array.
   - Insert the removed element back into the sorted array at the correct position.
*/

class soluction {
public:
    void insert(vector<int>& arr, int element) {
        // Base case: If the array is empty or the last element is less than or equal to the element
        if (arr.empty() || arr.back() <= element) {
            arr.push_back(element);
            return;
        }
        
        // Remove the last element
        int last = arr.back();
        arr.pop_back();
        
        // Recursively insert the element
        insert(arr, element);
        
        // Push the last element back
        arr.push_back(last);
    }

    void sortArray(vector<int>& arr) {
        // Base case: If the array has one or zero elements, it is already sorted
        if (arr.size() <= 1) {
            return;
        }
        
        // Remove the last element
        int last = arr.back();
        arr.pop_back();
        
        // Recursively sort the remaining array
        sortArray(arr);
        
        // Insert the removed element back into the sorted array
        insert(arr, last);
    }
};