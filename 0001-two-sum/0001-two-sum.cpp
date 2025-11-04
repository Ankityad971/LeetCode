class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> brr;
       int i;
       //dffd
        for ( i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    brr.push_back(i);
                    brr.push_back(j);

                    return brr; // return as soon as the answer is found it
                }
            }
        }
        return brr; // return empty vector if no solution found
    }
};
