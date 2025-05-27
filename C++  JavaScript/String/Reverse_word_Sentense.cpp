/* Reverse words in a sentence
 example :
  input : "Hello World"
  output: "olleH dlroW"
   input: " My name is Abhijit"
  output: "yM eman si tijihbA"
    
    Approach: 
    1. take a stack char
    2 take a empty string
    3. traverse the string
    4. if the character is not space, push it to the stack
    5. if the character is space, pop all characters from the stack and append to the string
    6. after the loop, pop all characters from the stack and append to the string
    7. return the string

*/

// C++ program to reverse words in a sentence
string reverseWords(string str) {
    stack<char> st;
    string result = "";

    for (int i = 0; i < str.length(); ++i) {
        if (str[i] != ' ') {
            st.push(str[i]);
        } else {
            while (!st.empty()) {
                result += st.top();
                st.pop();
            }
            result += " "; // Add space after the word
        }
    }

    // Reverse the last word (since it may not end with a space)
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}
