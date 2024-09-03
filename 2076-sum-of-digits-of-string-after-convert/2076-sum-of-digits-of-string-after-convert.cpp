class Solution {
public:
    int getLucky(string s, int k) {
        // Step 1: Convert the string s into a number string
        string numberStr = "";
        for (char c : s) {
            int num = c - 'a' + 1; // Find the alphabet position
            numberStr += to_string(num); // Append the number string to the result
        }
        
        // Step 2: Perform the transformations
        int sum = 0;
        for (char c : numberStr) {
            sum += c - '0'; // Sum up all the digits
        }

        // Perform (k-1) additional transformations
        for (int i = 1; i < k; ++i) {
            int newSum = 0;
            while (sum > 0) {
                newSum += sum % 10; // Sum the digits of the current number
                sum /= 10;
            }
            sum = newSum; // Update sum with the transformed number
        }

        return sum; // The resulting integer after k transformations
    }
};
