/* Josephus Problem
   The Josephus problem is a theoretical problem related to a certain elimination game.
   In this game, people are arranged in a circle and every k-th person is eliminated until only one person remains.
   The task is to find the position of the last remaining person.

   This implementation uses a queue to simulate the elimination process.

   example:
   input: n = 7, k = 3
   output: The last remaining person is at position 4.

   Approach:
   1. Create a queue and enqueue all people from 1 to n.
    2. While there is more than one person in the queue:
        a. Rotate the queue k-1 times to bring the k-th person to the front.
        b. Dequeue (remove) the k-th person from the queue.
    3. The last remaining person is the one at the front of the queue.
    4. Return the position of the last remaining person.
*/
class soluction {
public:
    int josephus(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            q.push(i);
        }

        while (q.size() > 1) {
            for (int i = 0; i < k - 1; ++i) {
                int front = q.front();
                q.pop();
                q.push(front);
            }
            q.pop(); // Remove the k-th person
        }

        return q.front(); // The last remaining person
    }
};

// modulas approach
class Solution {
public:
    int josephus(int n, int k) {
        if (n == 1) {
            return 0; // Base case: if there's only one person, they are the winner
        }
        return (josephus(n - 1, k) + k) % n; // Recursive relation
    }

    int findWinner(int n, int k) {
        return josephus(n, k) + 1; // Convert to 1-based index
    }
};