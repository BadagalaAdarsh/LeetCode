class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        int total_product = 1, product_without_zero =  1;
        int count_zero = 0;
        
        for(auto num: nums){
            total_product *= num;
            
            if (num == 0){
                count_zero++;
            }
            
            else{
                product_without_zero *= num;
            }
        }
        
        vector<int> answer(n);
        
        if ( total_product != 0){
            for(int i = 0; i < n ; i++){
                answer[i] = total_product / nums[i];
            }
        }
        
        else if(count_zero == 1){
            for(int i = 0; i < n ; i++){
                if (nums[i] == 0){
                    answer[i] = product_without_zero;
                }
            }
        }
        
        return answer;
    }
};