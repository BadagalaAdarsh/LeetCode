class Solution {
private:
    int target;
    vector<vector<int>> result;
    vector<int> temp;
    
    void dfs(vector<vector<int>>& graph, int currNode = 0) {
        temp.push_back(currNode);
        
        if(currNode == target) result.push_back(temp);
        
        else {
            for(int node: graph[currNode]) {
                dfs(graph, node);
            }
        }
        
        temp.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        target = graph.size() - 1;
        dfs(graph);
        return result;
    }
};