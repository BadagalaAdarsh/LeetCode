class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int count = 0;
        
        for(char ch: word){
            
            if('A' <= ch && ch <= 'Z') count++;
        }
        
        if(count == 1 && 'A' <= word[0]&& word[0] <= 'Z')
            return true;
        
        return count == (int)word.size() || count == 0;
        
    }
};