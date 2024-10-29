class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;  // Use long long to handle INT_MIN safely
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) {  // If N is odd
                result *= x;
            }
            x *= x;    // Square the base
            N /= 2;    // Reduce exponent by half
        }

        return result;
    }
};
