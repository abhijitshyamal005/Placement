/* Here we find  the middle of a Linked List and delete it;

example:
input: 1 -> 2 -> 3 -> 4 -> 5
output: 1 -> 2 -> 4 -> 5
 time complexity: O(n)
 space complexity: O(1)
*/
// c++ code

class soluctin {
public:
    Node* findMiddleAndDelete(Node* head) {
        if (!head || !head->next) return nullptr; // If list is empty or has one element

        Node *slow = head, *fast = head, *prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Now 'slow' is at the middle node
        if (prev) {
            prev->next = slow->next; // Delete the middle node
        }

        return head; // Return the modified list
    }

}