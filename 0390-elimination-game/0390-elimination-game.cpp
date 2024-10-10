class Solution {
public:
    int lastRemaining(int n) {
        return helper(n, true, 1, 1);
    }
    
    int helper(int n, bool left, int step, int head) {
        if (n == 1) {
            return head;  // Base case: when there's only one element left
        }
        
        // If we're removing from the left, or the length of the sequence is odd
        if (left || n % 2 == 1) {
            head += step;  // Update the head to the next element
        }
        
        // Recurse to the next level with half the elements and double the step size
        return helper(n / 2, !left, step * 2, head);
    }
};
