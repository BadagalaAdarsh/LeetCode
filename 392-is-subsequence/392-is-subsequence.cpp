class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if(s.size() == 0) return true;
        
        int sPointer = 0;
        int tPointer = 0;
        
        while(tPointer < t.size()){
            
            if (t[tPointer] == s[sPointer]){
                sPointer++;
                
                if(sPointer == s.size())
                    return true;
            }
            tPointer++;
        }
        
        return false;
    }
};