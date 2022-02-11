class Solution {
private:
    bool present(string s2, int freq[], int start, int length) {
        
        int tempFreq[26] = {0};
        
        for(int index = start; index < s2.size() && index < start + length; index++){
            
            char currentChar = s2[index];
            
            tempFreq[currentChar - 'a']++;
        }
        
        for(int index = 0; index < 26; index++){
            if (tempFreq[index] != freq[index])
                    return false;
        }
        
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        
     int freq[26] = {0};
        
        for(char ch: s1) {
            freq[ch - 'a']++;
        }
        
        for(int index = 0; index < s2.size(); index++) {
            
            char currentChar= s2[index];
            
            if(freq[currentChar - 'a']){
                
                if (present(s2, freq, index, s1.size())){
                    return true;
                }
            }
        }
        
        return false;
    }
};