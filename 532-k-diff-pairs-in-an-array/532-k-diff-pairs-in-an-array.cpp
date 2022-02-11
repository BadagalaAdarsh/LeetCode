class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int,int> a;
        for(int i: nums) 
            a[i]++;
        
        int answer = 0;
        
        for(auto x: a) {
            
            if(k == 0){
                if(x.second > 1) 
                    answer++;
            }
            
            else if (a.find(x.first + k) != a.end()) {
                answer++;
            }
            
        }
        
        return answer;
    }
};