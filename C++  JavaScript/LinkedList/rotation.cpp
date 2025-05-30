/* Rotation of a link list after k nodes 

example :
input: 1 -> 2 -> 3 -> 4 -> 5, k = 2
output: 3 -> 4 -> 5 -> 1 -> 2

input: 1 -> 2 -> 3, k = 1
output: 2 -> 3 -> 1

Approach:
1. Find the length of the linked list.
2. If k is greater than the length, take k modulo length.
3. If k is 0, return the original list.
4. Traverse the list to find the kth node.
5. Set the next pointer of the kth node to nullptr.
6. Traverse to the end of the list and set its next pointer to the head.
7. Return the new head of the rotated list.

*/
// C++ code
class Solution {

public:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* rotate(Node* head, int k) {
        if (!head || k <= 0) return head;

        // Step 1: Find the length of the linked list
        Node* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }

        // Step 2: If k is greater than length, take k modulo length
        k = k % length;
        if (k == 0) return head; // No rotation needed

        // Step 3: Find the kth node
        current = head;
        for (int i = 1; i < length - k; i++) {
            current = current->next;
        }

        // Step 4: Set the next pointer of the kth node to nullptr
        Node* newHead = current->next;
        current->next = nullptr;

        // Step 5: Traverse to the end of the list and set its next pointer to the old head
        Node* tail = newHead;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head;

        return newHead; // Return the new head of the rotated list
    }
};