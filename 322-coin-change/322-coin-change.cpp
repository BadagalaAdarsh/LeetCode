class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> numberOfCoinsRequired(amount+1, INT_MAX);
        
        sort(coins.begin(), coins.end());
        
        numberOfCoinsRequired[0] = 0;
        
        for(int currentAmount = 1; currentAmount <= amount; currentAmount++) {
            
            for(int coin: coins) {
                
                if (currentAmount - coin < 0) break;
                
                if ( numberOfCoinsRequired[currentAmount - coin] != INT_MAX) {
                    
                    numberOfCoinsRequired[currentAmount] = min(numberOfCoinsRequired[currentAmount], numberOfCoinsRequired[currentAmount - coin] + 1);
                }
            }
        }
        
        return numberOfCoinsRequired[amount] == INT_MAX ? -1 : numberOfCoinsRequired[amount];
        
    }
};