class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);

        long long num = 0;
        int sum = 0;

        for (char c : s) {
            int d = c - '0';
            sum += d;

            if (d != 0)
                num = num * 10 + d;
        }

        return num * 1LL * sum;
    }
};