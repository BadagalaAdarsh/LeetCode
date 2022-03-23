class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            
        unordered_map<string,vector<string>> hashtable;
        
        for(string s: strs){
            string copy = s;
            sort(copy.begin(),copy.end());
            
            hashtable[copy].push_back(s);
        }
        
        vector<vector<string>> answer;
        for(auto pointer: hashtable){
            answer.push_back(pointer.second);
        }
        
        return answer;
    }
};