class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int currentSum = 0;
        int maxSum = INT_MIN;

        for (int x : nums) {
            currentSum = max(x, currentSum + x);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};