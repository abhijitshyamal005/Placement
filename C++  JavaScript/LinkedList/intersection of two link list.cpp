/* Intersection of Two Linked Lists
 * 
 * This code finds the intersection point of two singly linked lists.
 * 
 * Example:
 * Input: List1: 1 -> 2 -> 3 -> 4 -> 5
 *        List2: 6 -> 7 -> 3 -> 4 -> 5
 * Output: Intersection at node with value 3
 * 
 * Approc
 * 
 * Time Complexity: O(n + m) where n and m are the lengths of the two lists.
 * Space Complexity: O(1)
 Approaches:
 * 1. Use a hash set to store the nodes of one list and check for intersection in the other.
    * 2. Use two pointers to traverse both lists and find the intersection point.
    * 3. Calculate the lengths of both lists, find the difference, and align the pointers to find the intersection.
 */
class solution {
public:
    Node* getIntersectionNode(Node* headA, Node* headB) {
        if (!headA || !headB) return nullptr;
        Node *a = headA, *b = headB;

        // Traverse both lists
        while (a != b) {
            a = a ? a->next : headB; 
            b = b ? b->next : headA; 
        }

        return a; 
    }
};

// using hash set 
class solution {
public:
    Node* getIntersectionNode(Node* headA, Node* headB) {
        unordered_set<Node*> nodes;
        
        // Store all nodes of the first list in a hash set
        while (headA) {
            nodes.insert(headA);
            headA = headA->next;
        }
        
        // Check if any node of the second list is in the hash set
        while (headB) {
            if (nodes.find(headB) != nodes.end()) {
                return headB; // Intersection found
            }
            headB = headB->next;
        }
        
        return nullptr; // No intersection
    }
};
