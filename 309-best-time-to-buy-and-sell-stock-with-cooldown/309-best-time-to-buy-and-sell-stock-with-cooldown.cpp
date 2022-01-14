class Solution {
public:
int maxProfit(vector<int>& prices) {
        int len=prices.size();
        
        //if len==1, just REST and get max profit 0
        if(len<=1)return 0;
        //REST for 2 days Or buy in day0 sell in day1
        if(len==2)return max(0,prices[1]-prices[0]);
        
        // if at least 3 days
        vector<int> buy(len,0);
        vector<int> sell(len,0);

        buy[0]=-prices[0];
        sell[1]=buy[0]+prices[1];
        buy[1]=-prices[1];
        sell[2]=max(buy[1]+prices[2],sell[1]-prices[1]+prices[2]);
        buy[2]=-prices[2];
        
        int max_profit=max(sell[2],max(sell[1],0)); //0 means rest for 3 days

        for(int i=3;i<len;i++){
            sell[i]=max(buy[i-1]+prices[i],sell[i-1]-prices[i-1]+prices[i]);
            buy[i]=max(sell[i-2]-prices[i],buy[i-1]+prices[i-1]-prices[i]);
            if(sell[i]>max_profit)max_profit=sell[i];
        }
        return max_profit;
    }
};