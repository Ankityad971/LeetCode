class Solution {
public:
    int majorityElement(vector<int>& nums) {
             int el= 0;
        int cn=0;
        for (int i=0;i<nums.size();i++){
            if (cn==0) {
                el= nums[i];
                cn++;
                
            }
            else if (nums[i]==el ) cn++;
            else cn--;
            
        }
        
        
        
        
        return el;
    }
};