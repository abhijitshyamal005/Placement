/* Floyd's Cycle-Finding Algorithm (Tortoise and Hare) in C++
in this algorithm we find the cycle in a linked list
example :
input: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
         ^                                         |
         |_________________________________________|
output: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
This code is a simple implementation of Floyd's Cycle-Finding Algorithm

Appproach:
1. Initialize two pointers, slow and fast.
2. Move slow pointer one step at a time and fast pointer two steps at a time.
3. If there is a cycle, the fast pointer will eventually meet the slow pointer.

*/

// Question 1:   Detection of cycle in linked list has present or not

// Approch 1 : using Map

class Solution {
    public:
    boolean hasCycle(ListNode head) {
    if(!head || !head->next) return false;
    unordered_map<ListNode*, bool> visited;
    ListNode* current = head;
    while(current) {
        if(visited[current]) return true; // Cycle detected
        visited[current] = true; // Mark the node as visited
        current = current->next; // Move to the next node
    }
    return false; // No cycle detected
    }

// Approch 2 : using Floyd's Cycle-Finding Algorithm (Tortoise and Hare)

class solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode *slow = head, *fast = head->next;
        
        while (slow != fast) {
            if (fast == NULL || fast->next == NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};


// Question 2:   Find the starting point of the cycle in linked list
// Approch 1 : using Map
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        unordered_map<ListNode*, bool> visited;
        ListNode* current = head;
        while (current) {
            if (visited[current]) return current; // Cycle detected, return the starting node
            visited[current] = true; // Mark the node as visited
            current = current->next; // Move to the next node
        }
        return NULL; // No cycle detected
    }
};

// Approch 2 : using Floyd's Cycle-Finding Algorithm (Tortoise and Hare)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode *slow = head, *fast = head;
        
        // Step 1: Detect cycle using Floyd's algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break; // Cycle detected
        }
        
        // If no cycle detected
        if (slow != fast) return NULL;
        
        // Step 2: Find the starting point of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow; // Starting point of the cycle
    }
};

// Question 3:   Find the length of the cycle in linked list
class Solution {
public:
    int cycleLength(ListNode *head) {
        if (!head || !head->next) return 0;
        ListNode *slow = head, *fast = head;
        
        // Step 1: Detect cycle using Floyd's algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break; // Cycle detected
        }
        
        // If no cycle detected
        if (slow != fast) return 0;
        
        // Step 2: Calculate the length of the cycle
        int length = 1;
        ListNode *current = slow->next;
        while (current != slow) {
            length++;
            current = current->next;
        }
        
        return length; // Length of the cycle
    }
};

// Question 4:  remove the cycle in linked list
class Solution {
public:
    void removeCycle(ListNode *head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head;
        
        // Step 1: Detect cycle using Floyd's algorithm
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break; // Cycle detected
        }
        
        // If no cycle detected
        if (slow != fast) return;
        
        // Step 2: Find the starting point of the cycle
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Step 3: Remove the cycle
        ListNode *cycleStart = slow;
        ListNode *current = cycleStart;
        while (current->next != cycleStart) {
            current = current->next; // Find the last node in the cycle
        }
        current->next = NULL; // Break the cycle
    }
};