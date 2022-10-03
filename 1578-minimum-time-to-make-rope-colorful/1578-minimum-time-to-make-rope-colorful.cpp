class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int totalTime = 0;
        int i=0;
        int j = 0;
        
        while(j<colors.size())
        {
            int maxi = 0;
            int sum = 0;
            while(colors[i]==colors[j] && j<colors.size())
            {
                sum+=neededTime[j];
                maxi = max(maxi , neededTime[j]);
                j++;
            }
                sum -= maxi;
                totalTime += sum;
				i = j;
        }
       
        return totalTime;
    }
};
