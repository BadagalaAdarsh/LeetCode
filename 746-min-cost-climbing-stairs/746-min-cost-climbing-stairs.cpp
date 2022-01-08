class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int)cost.size();
        vector<int> array(n+1);
        
        if (n < 3){
            return *min_element(cost.begin(), cost.end());
        }
        
        array[0] = cost[0];
        array[1] = cost[1];
        
        for(int i = 2; i < n ; i++) {
            array[i] =cost[i] + min(array[i-1],array[i-2]);
        }
        
        array[n] = min(array[n-1],array[n-2]);
        return array[n];
        
    }
};