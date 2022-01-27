class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        map<char,int> lastIndex;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++) {
            lastIndex[s[i]] = i;            
        }
        
        int start;
        int end = lastIndex[s[0]];
        
        vector<int> answer;
        
        
        for(int i = 0; i < n; i++) {
            
            end = max(end, lastIndex[s[i]]);
            
            if (i == end) {
                answer.push_back(end - start + 1);
                start = i + 1;               
            }            
        }
        
        return answer;
    }
};