class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maxWealth = 0;
        int currentWealth = 0;
        
        int totalCustomers = accounts.size();
        int totalBanks = accounts[0].size();
        
        for(int currentCustomer = 0; currentCustomer < totalCustomers; currentCustomer++) {
            currentWealth = 0;
            
            for(int bank = 0; bank < totalBanks; bank++) {
                currentWealth += accounts[currentCustomer][bank];
            }
            
            maxWealth = max(maxWealth, currentWealth);
        }
        
        return maxWealth;
    }
};