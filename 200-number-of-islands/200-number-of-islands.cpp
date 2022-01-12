class Solution {
public:
    bool inside(int i, int j, int  H, int W){
        return 0 <= i && i < H && 0 <= j && j < W;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int H = grid.size();
        
        if(H == 0) return 0;
        int W = grid[0].size();
        
        vector<vector<bool>> visited(H, vector<bool>(W));
        vector<pair<int,int>> directions {{1,0},{0,1},{-1,0},{0,-1}};
        int answer = 0;
        
        
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++) {
                if (!visited[i][j] && grid[i][j] == '1'){
                    
                    queue<pair<int,int>> q;
                    q.emplace(i,j);
                    answer++;
                    
                    visited[i][j] = true;
                    
                    while(!q.empty()) {
                        pair<int,int> p = q.front();
                        q.pop();
                        
                        for(pair<int,int> dir: directions){
                            int new_row = p.first + dir.first;
                            int new_col = p.second + dir.second;
                            
                            if(inside(new_row,new_col, H, W) && visited[new_row][new_col] == false && grid[new_row][new_col] == '1'){
                                q.emplace(new_row, new_col);
                                visited[new_row][new_col] = true;
                            }
                        }
                    }
                }
            }
        }
        return answer;
    }
};