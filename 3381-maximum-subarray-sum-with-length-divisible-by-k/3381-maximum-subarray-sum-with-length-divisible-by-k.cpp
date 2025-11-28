
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 0) return 0;            // defensive
        if (k > n) return 0;            // no non-empty subarray with length multiple of k

        vector<long long> minPref(k, LLONG_MAX);
        long long pref = 0;
        long long ans = LLONG_MIN;

        // prefix sum at index 0 (no elements) has modulo 0 and value 0
        minPref[0] = 0;

        for (int j = 1; j <= n; ++j) {
            pref += nums[j-1];          // prefix sum of first j elements
            int mod = j % k;

            // If we have seen some i with same modulo, we can form a valid subarray (i, j]
            if (minPref[mod] != LLONG_MAX) {
                ans = max(ans, pref - minPref[mod]);
            }
            // update minimal prefix sum for this modulo for future j'
            minPref[mod] = min(minPref[mod], pref);
        }

        // If ans remained LLONG_MIN it means no valid subarray was found.
        // For k <= n there should always be at least one valid subarray of length k,
        // but keep defensive behavior: return 0 only when truly no valid subarray exists.
        if (ans == LLONG_MIN) return 0;
        return ans;
    }
};
