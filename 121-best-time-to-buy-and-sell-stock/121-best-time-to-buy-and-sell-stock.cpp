class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_so_far = INT_MAX;
        int profit = 0;
        
        for(int i = 0; i < prices.size(); i++) {
            
            if (prices[i] < min_so_far) {
                min_so_far = prices[i];
            }
            
            profit = max(profit, prices[i] - min_so_far);
        }
        
        return profit;
    }
};