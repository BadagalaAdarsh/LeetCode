class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0) return false;
        
        vector<bool> dp(s.size() + 1, false);
        
        dp[0] = true;
        
        set<string> dict;
        for(auto words: wordDict) dict.insert(words);
        
        for(int i = 1; i <= s.size(); i++) {
            for(int j= i -1; j >= 0; j--) {
                
                if(dp[j]){
                    string word = s.substr(j, i-j);
                    
                    if(dict.find(word) != dict.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};