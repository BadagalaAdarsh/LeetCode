class Solution {
    
private:
    bool bipartiteDFS(int node, vector<int> adj[], int color[]) {
        
        if (color[node] == -1) color[node] = 1;
        
        for(auto it: adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 ^ color[node];
                
                if(!bipartiteDFS(it, adj, color)) return false;
            }
            
            if(color[it] == color[node]) return false;
        }
        
        return true;
    }
    bool bipartite(vector<int> adj[], int N) {
        int color[N];
        memset(color, -1, sizeof color);
        
        for(int i = 0; i < N; i++) {
            
            if(color[i] == -1) {
                if (!bipartiteDFS(i, adj, color)) return false;
            }
        }
        
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int N = graph.size();
        
        vector<int> adj[N];
        
        for(int i = 0; i < N; i++) {
            for(auto j: graph[i]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
        
        if (bipartite(adj, N)) return true;
        return false;
    }
};