class Solution {
public:
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }
    
    bool canDistribute(long long x, int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long lcm12 = lcm(divisor1, divisor2);
        
        long long countDiv1 = x / divisor1;
        long long countDiv2 = x / divisor2;
        long long countDivBoth = x / lcm12;
        
        long long countArr1 = x - countDiv1;  // numbers not divisible by divisor1
        long long countArr2 = x - countDiv2;  // numbers not divisible by divisor2
        
        long long overlap = x - countDiv1 - countDiv2 + countDivBoth;  // numbers usable by both
        
        return (countArr1 >= uniqueCnt1) && (countArr2 >= uniqueCnt2) && (countArr1 + countArr2 - overlap >= uniqueCnt1 + uniqueCnt2);
    }
    
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long low = 1, high = 2e9, result = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canDistribute(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)) {
                result = mid;  // we found a valid solution, now try to minimize
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};
