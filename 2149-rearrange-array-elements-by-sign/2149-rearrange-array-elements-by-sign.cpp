class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> positive;
        vector<int> negative;
        
        for(int num: nums) {
            if(num < 0)
                negative.push_back(num);
        
            else
                positive.push_back(num);
        }
        
        vector<int> answer;
        
        int n = positive.size();
        
        for(int i = 0; i < n; i++) {
            answer.push_back(positive[i]);
            answer.push_back(negative[i]);
        }
        
        return answer;
    }
};