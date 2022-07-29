class Solution {
public:
    bool matches(string word, string pattern) {
        vector<char> pattern_to_word(26);
        vector<char> word_to_pattern(26);
        
        for(int index = 0; index < word.size(); index++) {
            char word_char = word[index];
            char pattern_char = pattern[index];
            
            if (pattern_to_word[pattern_char - 'a'] == 0){
                pattern_to_word[pattern_char - 'a'] = word_char;
            }
            
            if(word_to_pattern[word_char - 'a'] == 0) {
                word_to_pattern[word_char - 'a'] = pattern_char;
            }
            
            if (pattern_to_word[pattern_char - 'a'] != word_char ||
               word_to_pattern[word_char - 'a'] != pattern_char) {
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> answer;
        
        for (auto word: words) {
            if (matches(word, pattern)){
                answer.push_back(word);
            }
        }
        
        return answer;
        
    }
};
