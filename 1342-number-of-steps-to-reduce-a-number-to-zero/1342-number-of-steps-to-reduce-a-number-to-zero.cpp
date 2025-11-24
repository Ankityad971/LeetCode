class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) return 0;

        int ones = __builtin_popcount(num);      // count of 1 bits
        int bits = 31 - __builtin_clz(num);      // index of MSB
        return bits + ones;
    }
};
