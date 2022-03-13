class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        bool isUp = false;
        bool isDown = false;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]) isUp = true;
            if(nums[i] < nums[i-1]) isDown = true;
        }
        
        if(isUp && isDown) return false;
        return true;
        
    }
};