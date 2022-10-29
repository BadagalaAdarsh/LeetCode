class Solution {
public:
int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> plant(n);        
        
        for(int i=0; i<n; i++) {
			
            plant[i] = {growTime[i], plantTime[i]};
        }
        
		
        sort(plant.begin(), plant.end(),  greater<pair<int, int>>());
        
        int day = 0;
        int ans = 0;
        
        for(int i=0; i<n; i++) {
			
            day += plant[i].second;
			
            ans = max(ans, day+plant[i].first);
        }
        
        return ans;
    }
};
