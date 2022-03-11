class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        set<int> visited;
        
        for(int number: nums) {
            
            if(visited.find(number) != visited.end()) {
                return true;
            }
            
            visited.insert(number);
        }
        
        return false;
    }
};