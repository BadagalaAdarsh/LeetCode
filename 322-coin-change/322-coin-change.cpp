class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> numberOfCoins(amount +1, INT_MAX - 1); // -1 so that in min condition intmax + 1 dont get overflow
        sort(coins.begin(), coins.end());
        numberOfCoins[0] = 0;
        
        
        for(int i = 1; i <= amount; i++) {
            
            for(int j = 0; j < coins.size(); j++) {
                
                if (coins[j] > i ) {
                    break;
                }
                
                if ( i - coins[j] >= 0) {
                    numberOfCoins[i] = min(numberOfCoins[i], numberOfCoins[i - coins[j]] + 1);
                }                
            }
        }
        
        return numberOfCoins[amount] == INT_MAX - 1 ? -1 : numberOfCoins[amount];
        
    }
};