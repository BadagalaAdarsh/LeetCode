class NumMatrix {
    
    vector<vector<int>> answer;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        
        for(int i=0; i < matrix.size(); i++){
            for(int j=1; j < matrix[0].size(); j++){
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
         for(int i=1; i < matrix.size(); i++){
            for(int j=0; j < matrix[0].size(); j++){
                matrix[i][j] += matrix[i-1][j];
            }
        }
        
        for(int i=0; i<matrix.size(); i++){
            vector<int> temp = matrix[i];
            answer.push_back(temp);
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int total = answer[row2][col2];
        int extra = (col1!=0?answer[row2][col1-1]:0) + (row1!=0?answer[row1-1][col2]:0) - ((row1!=0 && col1!=0)?answer[row1-1][col1-1]:0);
        
        return total - extra;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */