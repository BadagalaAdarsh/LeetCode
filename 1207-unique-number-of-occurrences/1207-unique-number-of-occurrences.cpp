class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        map<int,int> freq;
        
        for(int num: arr) {
            freq[num]++;
        }
        
        set<int> occur;
        for(auto num: freq){
            occur.insert(num.second);
        }
        
        return occur.size() == freq.size();
    }
};