/*
Here we found the Largest elemnt And the 2nd largest elemnt of the Array
for example : arry [7, 4, 5, 6, 8, 9]
then the largest elemnt is 9 and the 2nd largest elemnt is 8
Approch1 : 
Two pointer Approch  for finding the largest and 2nd largest elemnt

time complexity is O(n)

*/

// C++ code

int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    int largest = INT_MIN;
    int SecLargest = INT_MIN;

    if(n<2)
    {
        return -1;
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i]>largest){
        SecLargest=largest;
         largest = arr[i];

    }
    else if(arr[i]>SecLargest && arr[i]!=largest ) SecLargest =arr[i];
    }
    return SecLargest == INT_MIN ? -1 : SecLargest ;

}

// JavaScript code

function findSecondLargest(n, arr) {
    // Write your code here.
    let largest = Number.MIN_VALUE;
    let SecLargest = Number.MIN_VALUE;

    if (n < 2) {
        return -1;
    }

    for (let i = 0; i < n; i++) {
        if (arr[i] > largest) {
            SecLargest = largest;
            largest = arr[i];
        } else if (arr[i] > SecLargest && arr[i] != largest) {
            SecLargest = arr[i];
        }
    }
    return SecLargest == Number.MIN_VALUE ? -1 : SecLargest;
}