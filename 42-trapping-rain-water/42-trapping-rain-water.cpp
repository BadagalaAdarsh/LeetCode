class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int left = 0, right = n-1;
        int max_left = 0, max_right = 0;
        
        int res = 0;
        
        while(left <= right) {
            
            if (height[left] <= height[right]) {
                if (height[left] >= max_left) max_left = height[left];
                else res += max_left - height[left];
                
                left++;
            }
            
            else{
                if(height[right] >= max_right) max_right = height[right];
                else res += max_right - height[right];
                
                right--;
            }
        }
        
        return res;        
    }
};