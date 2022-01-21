class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int answer = 0;
        
        for(int number: nums) {
            answer ^= number;
        }
        
        return answer;
    }
};