class Solution {
public:
    int get(int x, vector<int> &parent){
        return parent[x] = parent[x] == x? x: get(parent[x], parent);
    }
    void merge(int l, int r, vector<int> &parent, vector<int>&rank){
        l = get(l, parent);
        r = get(r, parent);
        if(rank[l] == rank[r]) rank[l]++;
        if(rank[l] > rank[r]) parent[r] = l;
        else parent[l] = r;
        return ;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int totalEdges = connections.size();
        if(totalEdges < n-1) return -1;
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            merge(u,v, parent, rank);
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(parent[i] == i) count++;
        }
        return count-1;
        
    }
};