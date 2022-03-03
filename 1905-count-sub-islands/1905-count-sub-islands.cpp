class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int height = grid2.size();
        if (height == 0 || grid2[0].size() == 0) {
            return 0;
        }
        
        int answer = 0;
        
        int width = grid2[0].size();
        vector<vector<bool>> visited(height, vector<bool>(width));
        vector<pair<int,int>> directions {{1,0},{0,1},{-1,0},{0,-1}};
        
        auto inside = [&](int row, int col) {
            return 0 <= row && row < height && 0 <= col && col < width;
        };
        
        for(int row = 0; row < height; row++) {
            for(int col = 0; col < width; col++) {
                
                
                
                if (grid2[row][col] == 1 && !visited[row][col]) {
                    
                    queue<pair<int,int>> q;
                    q.push({row,col});
                    bool flag = true;
                    
                    if (grid1[row][col] != 1){
                        flag = false;
                    }
                    
                    visited[row][col] = true;
                    
                    while (!q.empty()) {
                        pair<int,int> p = q.front();
                        q.pop();
                        
                        for(pair<int,int> dir: directions) {
                            int new_row = p.first + dir.first;
                            int new_col = p.second + dir.second;
                            if ( inside(new_row, new_col) && grid2[new_row][new_col] == 1 && !visited[new_row][new_col]){
                                visited[new_row][new_col] = true;
                                q.push({new_row,new_col});
                                if (grid1[new_row][new_col] != 1){
                                    flag = false;
                                }
                            }
                        }
                    }
                    
                    if (flag){
                        answer++;
                    }
                }
            }
        }
        return answer;
    }
};