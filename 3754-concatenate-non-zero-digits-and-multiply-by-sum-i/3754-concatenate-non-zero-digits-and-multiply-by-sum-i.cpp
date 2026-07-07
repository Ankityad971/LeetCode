class Solution {
public:
    long long sumAndMultiply(int n) {

        long long an = 0;
        int sum = 0;
        while (n > 0) {
            int r = n % 10;
            if (r != 0)
                an = an * 10 + r;
            n /= 10;
            sum += r;
        }

        long long f = 0;
        while (an > 0) {
            int r = an % 10;
            f = f * 10 + r;
            an /= 10;
        }
        
            return f * sum;

        return f;
    }
};