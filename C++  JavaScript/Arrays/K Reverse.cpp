/*
 here we reverese the array after k position
 for example: input arr = [1,2,3,4,5,6,7,8,9] , k = 3
 output arr = [1,2,3,4,9,8,7,6,5]

 concept: after k position we reverse the array

 Approach:
    we take two pointers first and last
    first = k+1
    last = n-1
    then we swap the elements at first and last
    then we move the pointers

    time complexity : O(n)
*/

// c++ code

void reverseArray(vector<int> &arr , int m) {
    
    int start= m+1;
    int end = arr.size()-1;
    while(start<=end)
    {
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;

    }      	
}


// JavaScript code
function reverseArray(arr, m) {
    let start = m + 1;
    let end = arr.length - 1;

    while (start <= end) {
        // swap the elements at start and end
        let temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // move the pointers
        start++;
        end--;
    }
}