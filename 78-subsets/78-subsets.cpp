class Solution {
private:
    void function(int start, int end, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        
        if(start == end) {
            ans.push_back(temp);
            return;
        }
        
        
        
        // including
        temp.push_back(nums[start]);
        function(start + 1, end, nums, temp, ans);
        
        // not including
        temp.pop_back();
        function(start + 1, end, nums, temp, ans);
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        vector<int> temp;
        function(0, nums.size(), nums, temp, ans);
        
        return ans;
    }
};