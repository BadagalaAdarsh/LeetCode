class Solution {
    
private:
    void getCombinations(int start, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans){
        
        if (target == 0){
            ans.push_back(ds);
            return;
        }
        
        if (start == candidates.size()){
            
            return;
        }
        
        if (candidates[start] <= target){
            ds.push_back(candidates[start]);
            getCombinations(start, candidates, target - candidates[start], ds, ans);
            ds.pop_back();
        }
        
        getCombinations(start+1, candidates, target, ds, ans);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        getCombinations(0, candidates, target, ds, ans);
        
        return ans;
    }
};