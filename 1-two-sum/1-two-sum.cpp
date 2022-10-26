class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> answer;
        
        for(int left = 0; left < nums.size(); left++){
            
            for(int right = left + 1; right < nums.size(); right++){
                
                if(nums[left] + nums[right] == target) {
                   answer.push_back(left);
                    answer.push_back(right);
                }
            }
        }
         
        return answer;
    }
};
