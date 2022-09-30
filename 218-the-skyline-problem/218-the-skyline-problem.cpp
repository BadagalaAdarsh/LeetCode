class Solution {
public:
vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        priority_queue<vector<int>> live;   
        int n=b.size();
        
        int cur=0;
        vector<vector<int>> ans;
        while(cur<n || !live.empty()){
            int cur_x=live.empty()?b[cur][0]:live.top()[1];
            
            
            if(cur>=n || b[cur][0]>cur_x){
                while(!live.empty() && (live.top()[1]<=cur_x)){
                    live.pop();
                }
            }
            else{

                cur_x=b[cur][0];
                while(cur<n && cur_x==b[cur][0]){
                    live.push({b[cur][2],b[cur][1]});
                    cur++;
                }
            }
            

            int cur_h=live.empty()?0:live.top()[0];
            if(ans.empty() || ans[ans.size()-1][1]!=cur_h){
                ans.push_back({cur_x,cur_h});
            }
        }
        return ans;
    }
};
