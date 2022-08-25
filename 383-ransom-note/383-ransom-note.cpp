class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> alphabets(26);
        
        for(char ch: magazine){
            alphabets[ch - 'a']++;
        }
        
        for(char ch: ransomNote) {
            alphabets[ch - 'a']--;
        }
        
        for(int num: alphabets){
            if(num < 0)
                return false;
        }
        
        return true;
    }
};
