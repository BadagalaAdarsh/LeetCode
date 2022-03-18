class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> dict(256, 0);
        vector<bool> visited(256, false);
        
        for(auto ch: s) dict[ch]++;
        
        string result = "0";
        
        for(auto c: s){
            dict[c]--;
            
            if(visited[c]) continue;
            
            while(c < result.back() && dict[result.back()]){
                visited[result.back()] = false;
                result.pop_back();
            }
            
            result += c;
            visited[c] = true;
        }
        
        return result.substr(1);
    }
};