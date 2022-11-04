class Solution {
public:
    string reverseVowels(string s) {
        
        vector<char> vowel;
        set<char> check({'a','e','i','o','u','A','E','I','O','U'});
        
        for(char ch: s){
            
            if (check.find(ch) != check.end()) {
                vowel.push_back(ch);
            }
            
        }
        
        int j = 0;
        reverse(vowel.begin(), vowel.end());
        
        for(int i = 0; i < s.size(); i++) {
            
            if(check.find(s[i]) != check.end()) {
                s[i] = vowel[j++];
            }
        }
        
        return s;
    }
};