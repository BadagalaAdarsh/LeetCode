class Solution {
private:
    void findCombinations(int start, int target, vector<int>& array, vector<vector<int>>& ans, vector<int>& ds){
        
        if (target == 0){
            ans.push_back(ds);
            return;
        }
        
        for(int i = start; i < array.size(); i++) {
            if (i > start && array[i] == array[i-1]) continue;
            
            if(array[i] > target) break;
            
            ds.push_back(array[i]);
            findCombinations(i+1, target - array[i], array, ans, ds);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        
        findCombinations(0, target, candidates, ans, ds);
        
        return ans;
    }
};