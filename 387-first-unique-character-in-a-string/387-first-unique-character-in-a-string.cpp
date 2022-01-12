class Solution {
public:
    int firstUniqChar(string s) {
        
        map<char, pair<int,int>> hash;
        
        for(int i = 0; i < s.size(); i++) {
            hash[s[i]].first++;
            hash[s[i]].second = i;
        }
        int index = s.size();
        for(auto &p: hash) {
            if (p.second.first == 1) 
                index = min(index, p.second.second);
        }
        
        return index == s.size() ? - 1: index;
        
    }
};