/* here we sort aLinked list 
example :
 input: 4 -> 2 -> 1 -> 3
 output: 1 -> 2 -> 3 -> 4

 Approach:
 use MArge Sort algorithm to sort the linked list.

*/  
// c++ program to sort a linked list using merge sort
class solution {
public:
    // function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        if (left->data < right->data) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    // function to split the linked list into two halves
    Node* split(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = slow->next;
        slow->next = nullptr; 
    }

    // main function to sort the linked list using merge sort
    Node* sortList(Node* head) {
        if (!head || !head->next) return head;

        Node* secondHalf = split(head);
        head = sortList(head);
        secondHalf = sortList(secondHalf);

        return merge(head, secondHalf);
    }
};