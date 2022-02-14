class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        
        int startX = startPos[0];
        int startY = startPos[1];
        
        map<char, pair<int,int>> hashmap = {{'L',{0, -1}}, {'R',{0,1}}, {'U',{-1,0}}, {'D',{1,0}}};
        
        vector<int> answer;
        
        int count;
        
        for(int i = 0; i < (int)s.size(); i++) {
            count = 0;
            
            int newX = startX;
            int newY = startY;
            
            for(int j = i; j < (int)s.size(); j++) {
                newX += hashmap[s[j]].first;
                newY += hashmap[s[j]].second;
                
                if (newX >= n || newY >= n || newX < 0 || newY < 0) break;
                
                count++;
            }
            answer.push_back(count);
        }
        
        return answer;
    }
};