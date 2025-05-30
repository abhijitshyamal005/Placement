/* reverse Linked List
 * 
 * This code defines a function to reverse a singly linked list.
 * The function iterates through the list, reversing the pointers of each node.
 * It returns the new head of the reversed list.
 exaple :
 input: 1 -> 2 -> 3 -> 4 -> 5
 * output: 5 -> 4 -> 3 -> 2 -> 1

 input: 1 -> 2 -> 3
 * output: 3 -> 2 -> 1
 Approch:
 * 1. Initialize three pointers: prev, curr, and next.
    * 2. Set prev to nullptr and curr to the head of the list.
    * 3. Iterate through the list until curr is nullptr:
        * a. Store the next node in next.
        * b. Reverse the pointer of curr to point to prev.
        * c. Move prev to curr and curr to next.
        * 4. After the loop, prev will be the new head of the reversed list.
        * 5. Return prev as the new head of the reversed list.
        * Time Complexity: O(n), where n is the number of nodes in the list.
Approch2 :
using stack
 * 1. Initialize an empty stack.
 * 2. Traverse the linked list and push each node onto the stack.
 * 3. Pop nodes from the stack and adjust their next pointers to reverse the list.
 * 4. Set the next pointer of the last popped node to nullptr.
 * 5. Return the new head of the reversed list.
 * Time Complexity: O(n), where n is the number of nodes in the list.

*/

// c++ code Approch 1

class solution {
public:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next; // Store the next node
            curr->next = prev; // Reverse the pointer
            prev = curr;       // Move prev to current node
            curr = next;       // Move to the next node
        }
        return prev; // New head of the reversed list
    }
};