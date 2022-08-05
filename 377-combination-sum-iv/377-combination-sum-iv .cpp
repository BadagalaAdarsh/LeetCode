class Solution {
public:
    unsigned int combinationSum4(vector<int>& nums, int target) {
        
        vector<unsigned int> table(target+1,0);
        
        table[0] = 1;
        
        for(int i = 1; i <= target; i++){
            
            for(int num: nums){
                
                if (i-num >= 0){
                    table[i] += table[i - num];
                }
            }
        }
        
        return table[target];
        
    }
};
