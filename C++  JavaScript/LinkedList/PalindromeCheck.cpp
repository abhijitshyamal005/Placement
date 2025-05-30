/* Here we check if a linked list is a palindrome.
   A linked list is a palindrome if the sequence of values from the head to the tail is the same as from the tail to the head.
   This implementation uses a two-pointer technique to find the middle of the list and then compares the first half with the reversed second half.
    Example:
    Input: 1 -> 2 -> 3 -> 2 -> 1
    Output: true

    input: 1 -> 2 -> 3 -> 4
    Output: false

    Approach   1:
    Use a stack to store the first half of the linked list.
    Then, traverse the second half and compare it with the stack.
    time complexity: O(n)
    Space Complexity: O(n) for the stack.


Appriach 2:
    Use a two-pointer technique to find the middle of the linked list.
    Reverse the second half and compare it with the first half.
    Restore the original list if needed.

    Time Complexity: O(n)
    Space Complexity: O(n) for Approach 1, O(1) 

    Approach 3:
    convert in a vector and check if the vector is a palindrome.
    time complexity: O(n)
    Space Complexity: O(n)
*/


//c++ code 

//Approach 1: Using a stack

class solution {
public:
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        std::stack<int> stack;
        Node* current = head;

        // Push the first half of the linked list onto the stack
        while (current) {
            stack.push(current->data);
            current = current->next;
        }

        // Compare the second half with the stack
        current = head;
        while (current) {
            if (current->data != stack.top()) {
                return false; // Not a palindrome
            }
            stack.pop();
            current = current->next;
        }

        return true; // Is a palindrome
    }
};

// Approach 2: Using a two-pointer technique
class solution {
public:
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        Node *slow = head, *fast = head, *prev = nullptr;

        // Find the middle of the linked list
        while (fast && fast->next) {
            fast = fast->next->next;
            Node* nextSlow = slow->next;
            slow->next = prev; // Reverse the first half
            prev = slow;
            slow = nextSlow;
        }

        // If the length is odd, skip the middle element
        if (fast) {
            slow = slow->next;
        }

        // Compare the reversed first half with the second half
        while (prev && slow) {
            if (prev->data != slow->data) {
                return false; // Not a palindrome
            }
            prev = prev->next;
            slow = slow->next;
        }

        return true; // Is a palindrome
    }
};

// Approach 3: Using a vector

class solution {
public:
    bool isPalindrome(Node* head) {
        if (!head || !head->next) return true;

        std::vector<int> values;
        Node* current = head;

        // Store the values in a vector
        while (current) {
            values.push_back(current->data);
            current = current->next;
        }

        // Check if the vector is a palindrome
        int n = values.size();
        for (int i = 0; i < n / 2; ++i) {
            if (values[i] != values[n - 1 - i]) {
                return false; // Not a palindrome
            }
        }

        return true; // Is a palindrome
    }
};
