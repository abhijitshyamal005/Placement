/* here we are going to add two arrays .
   suppose
   input:  [1,2,3] and  [4,9]
 Output:  [1,7,2]
    because 3+9 = 12 so we will take 2 and carry 1 and 4+2 +1 = 7
    so the final result will be [1,7,2]

   Approach:
         sum = 3 + 9 = 12
         carry = 12 / 10 = 1
            result = 12 % 10 = 2
            arr[i] =2 ;
            arr[i-1] = arr[i-1] + carry;
    Here will be 3 cases:

    case 1: if first array is large than second array
    case 2: if second array is large than first array
    case 3: if both arrays are equal and there is a carry

*/

// C++ code

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{

    int i = n - 1; // Pointer for array a

    int j = m - 1; // Pointer for array b

    vector<int> ans;

    int carry = 0;

    // Loop until both arrays are exhausted

    while (i >= 0 && j >= 0)
    {

        int sum = a[i] + b[j] + carry;

        carry = sum / 10; // Calculate the carry for the next iteration

        sum = sum % 10; // Get the digit to store in the result

        ans.push_back(sum);

        i--;

        j--;
    }

    // If array a has remaining digits

    while (i >= 0)
    {

        int sum = a[i] + carry;

        carry = sum / 10;

        sum = sum % 10;

        ans.push_back(sum);

        i--;
    }

    // If array b has remaining digits

    while (j >= 0)
    {

        int sum = b[j] + carry;

        carry = sum / 10;

        sum = sum % 10;

        ans.push_back(sum);

        j--;
    }

    // If there's a carry left after processing both arrays

    while (carry != 0)
    {

        int sum = carry;

        carry = sum / 10;

        sum = sum % 10;

        ans.push_back(sum);
    }

    // Reverse the result vector (because we process the least significant digit first)

    reverse(ans.begin(), ans.end());

    return ans;
}



// JavaScript code
function findArraySum(a, b) {
    let n = a.length;
    let m = b.length;
    let i = n - 1; // Pointer for array a
    let j = m - 1; // Pointer for array b
    let ans = [];
    let carry = 0;

    // Loop until both arrays are exhausted
    while (i >= 0 && j >= 0) {
        let sum = a[i] + b[j] + carry;
        carry = Math.floor(sum / 10); // Calculate the carry for the next iteration
        sum = sum % 10; // Get the digit to store in the result
        ans.push(sum);
        i--;
        j--;
    }

    // If array a has remaining digits
    while (i >= 0) {
        let sum = a[i] + carry;
        carry = Math.floor(sum / 10);
        sum = sum % 10;
        ans.push(sum);
        i--;
    }

    // If array b has remaining digits
    while (j >= 0) {
        let sum = b[j] + carry;
        carry = Math.floor(sum / 10);
        sum = sum % 10;
        ans.push(sum);
        j--;
    }

    // If there's a carry left after processing both arrays
    while (carry !== 0) {
        let sum = carry;
        carry = Math.floor(sum / 10);
        sum = sum % 10;
        ans.push(sum);
    }

    // Reverse the result vector (because we process the least significant digit first)
    return ans.reverse();
}