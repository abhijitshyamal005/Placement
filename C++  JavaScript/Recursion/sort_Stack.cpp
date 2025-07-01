/* Sort stack using recursion
This code defines a function to sort a stack using recursion.
Approch:
1. If the stack is empty, return.
2. Pop the top element from the stack.
3. Recursively sort the remaining stack.
4. Insert the popped element back into the sorted stack in the correct position.
5. The insert function is used to place the element in the correct position.

*/

class solution {
public:
    void sortStack(stack<int> &s) {
        if (s.empty()) {
            return;
        }
        
        int top = s.top();
        s.pop();
        
        sortStack(s);
        
        insert(s, top);
    }
}