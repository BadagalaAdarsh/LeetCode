class Solution {

private:


public:
        
    bool carPooling(vector<vector<int>>& trips, int capacity) {
            
        vector<pair<int,int>> time;
        
        for(int i = 0; i < trips.size(); i++) {
            
            time.push_back({trips[i][1], trips[i][0]}); // start time and number of passengers
            time.push_back({trips[i][2], -trips[i][0]}); // end time and minus of number of passengers as they are going to exit
        }
        
        sort(time.begin(), time.end());
        
        int filled = 0;
        
        for(int i = 0; i < time.size(); i++) {
            
            filled += time[i].second;
            if(filled > capacity) return false;
        }
        
        return true;
    }
};