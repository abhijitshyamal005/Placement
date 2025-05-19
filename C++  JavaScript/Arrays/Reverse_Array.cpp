/*
 here we simply reverse the array using two pointers
 for example input : [1,2,3,4,5]
    output : [5,4,3,2,1]

    Approach:
     first we take fist and last element of the array
     then we swap them
     then we move the first pointer to the right and last pointer to the left 

     time complexity : O(n)
*/

// c++ code

void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {
        // swap the elements at start and end
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // move the pointers
        start++;
        end--;
    }
}

// JavaScript code
function reverseArray(arr) {
    let start = 0;
    let end = arr.length - 1;

    while (start < end) {
        // swap the elements at start and end
        let temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // move the pointers
        start++;
        end--;
    }
}
