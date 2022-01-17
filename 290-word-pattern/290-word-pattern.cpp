class Solution {
private:
    vector<string> getWords(string s) {
        
        vector<string> words;
        istringstream ss(s);
        
        string word;
        
        while(ss >> word) {
            words.push_back(word);
        }
        
        return words;
    }
public:
    bool wordPattern(string pattern, string s) {     
        
        map<char,string> charToWord;
        map<string,char> wordToChar;
        vector<string> words = getWords(s);
        
        if(words.size() != pattern.size()) return false;
        
        for(int i = 0; i < pattern.size(); i++) {
            
            char currentChar = pattern[i];
            string currentWord = words[i];
            
            if(charToWord.find(currentChar) == charToWord.end() && wordToChar.find(currentWord) == wordToChar.end()) {
                charToWord[currentChar] = currentWord;
                wordToChar[currentWord] = currentChar;
            }
            
            else{
                string storedWord = charToWord[currentChar];
                char storedChar = wordToChar[currentWord];
                
                if(storedWord != currentWord || storedChar != currentChar) return false;
            }
        }
        
        return true;        
        
    }
};