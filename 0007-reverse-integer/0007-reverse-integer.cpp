class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Single compact overflow check
            if (result > 214748364 || result < -214748364) return 0;

            result = result * 10 + digit;
        }
        return result;
    }
};
