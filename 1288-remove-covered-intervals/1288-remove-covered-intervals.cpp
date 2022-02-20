class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        int result = 0, left = -1, right = -1;
        sort(intervals.begin(), intervals.end());
        
        for(auto v: intervals) {
            
            if(v[0] > left && v[1] > right) {
                result++;
                left = v[0];
            }
            
            right = max(right, v[1]);
        }
        
        return result;
    }
};