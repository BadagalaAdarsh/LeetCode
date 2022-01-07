class Solution {
private:
    
    int lowerBound(vector<int>& nums, int target) {
        
        int left = 0, right = nums.size() - 1;
        
        while(left <= right) {
            
            int mid = (right - left) / 2 + left;
            
            if (nums[mid] < target) 
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return left;
        
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int firstPosition = lowerBound(nums,target) ;
        int nextNumber = target + 1;
        
        int lastPosition = lowerBound(nums, nextNumber) - 1;
        
        if (firstPosition < nums.size() && nums[firstPosition] == target) 
            return {firstPosition, lastPosition};
        
        return {-1, -1};
        
    }
};