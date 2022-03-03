class Solution {
    
private:
    int Perimeter(int a, int b, int c){

        
        if((a+b) > c && (b + c) > a && (a + c) > b && (a - b) < c && (b - c) < a && (a - c) < b) {
            return a + b + c;
        }
        
        return 0;
    }
public:
    int largestPerimeter(vector<int>& nums) {
        
       
       int maxPermieter = 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i <= nums.size() - 3; i++){
            int currPerimeter = Perimeter(nums[i], nums[i+1], nums[i+2]);
            
            maxPermieter = max(maxPermieter, currPerimeter);
        }
        
        return maxPermieter;
    }
};