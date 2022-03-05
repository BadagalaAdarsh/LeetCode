class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int row = mat.size(), col = mat[0].size(), INF = row + col;
        
        for(int r = 0; r < row; r++) {
            
            for(int c = 0; c < col; c++) {
                
                if(mat[r][c] == 0) continue;
                
                int top = INF, left = INF;
                
                if(r-1 >= 0) top = mat[r-1][c];
                if(c-1 >=0) left = mat[r][c-1];
                
                mat[r][c] = min(top, left) + 1;
            }
        }
        
        
        for(int r = row - 1; r >= 0; r--) {
            for(int c = col - 1; c >=0; c--) {
                
                if(mat[r][c] == 0) continue;
                
                int bottom = INF, right = INF;
                
                if(r+1 < row) bottom = mat[r+1][c];
                if(c+1 < col) right = mat[r][c+1];
                
                mat[r][c] = min(mat[r][c], min(bottom, right) + 1);
                
            }
        }
        
        return mat;
        
    }
};