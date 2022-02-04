class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        for(int i = 0; i < (int)nums.size(); i++){
            
            if (nums[i] == 0){
                nums[i] = -1;
            }
        }
        
        vector<int> prefix_sum;
        prefix_sum.push_back(0);
        
        for(auto num: nums){
            prefix_sum.push_back(prefix_sum.back() + num);
        }
        
        unordered_map<int,int> first_occ;
        int answer = 0;
        
        for(int i=0; i < (int) prefix_sum.size(); i++){
            int x = prefix_sum[i];
            
            auto it = first_occ.find(x);
            if(it != first_occ.end()){
                answer = max(answer, i - first_occ[x]);
            }
            
            else{
                first_occ[x] = i;
            }
        }
        
        return answer;
        
    }
};