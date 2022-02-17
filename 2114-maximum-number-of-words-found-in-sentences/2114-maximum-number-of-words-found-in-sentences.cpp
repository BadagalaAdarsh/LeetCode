class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        int count = 0;
        unordered_set<string> hashset;
        
        for(string currentString: sentences){
            
            stringstream strstm(currentString);
            
            string tempString;
            int current = 0;
            
            while(strstm >> tempString) {
                hashset.insert(tempString);
                current++;
            }
            
            count = max(count, current);
            
        }
        
        return count;
    }
};