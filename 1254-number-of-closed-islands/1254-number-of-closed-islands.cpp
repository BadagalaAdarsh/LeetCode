class Solution {
    
    vector<int> directions = {0, 1, 0, -1, 0};
private:
    void fill(vector<vector<int>>& grid, int x, int y){
        
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 1)
            return;
        
        grid[x][y] = 1;
        
        fill(grid, x + 1, y);
        fill(grid, x, y + 1);
        fill(grid, x -1, y);
        fill(grid, x, y - 1);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        // filling the borders first where the value is 0
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if( (i == 0 || j == 0 || i == grid.size() - 1 || j  == grid[0].size() -1) && grid[i][j] == 0)
                    fill(grid, i, j);
            }
        }
        
        // now counting the remaining islands using the same fill algorithm
        // here i am modifiying the array and using it has visited array 
        // if we don't want to modify the array then we can use separate visited array
        
        int islands = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                
                if(grid[i][j] == 0){
                    islands++;
                    fill(grid, i, j);
                }
                    
            }
        }
        
        return islands;
    }
};