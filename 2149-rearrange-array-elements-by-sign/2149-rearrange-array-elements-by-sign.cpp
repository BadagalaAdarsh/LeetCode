class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> answer(n);
        
        int positive = 0, negative = 1;
        
        for(int num: nums){
            if(num > 0) {
                answer[positive] = num;
                positive += 2;
            }
            else{
                answer[negative] = num;
                negative += 2;
            }
        }
        
        return answer;
    }
};