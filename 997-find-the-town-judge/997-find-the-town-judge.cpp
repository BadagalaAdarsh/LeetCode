class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> indegree(n + 1, 0);
        
        for(int i = 0; i < trust.size(); i++) {
            
            int u = trust[i][1];
            indegree[u]++;
            u = trust[i][0];
            indegree[u]--;
            
        }
        
        for(int i = 1; i < n+1; i++) {

        
            if (indegree[i] == n-1){
                return i;
            }
        }
        
        return -1;
    }
};