class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        for(int i = 1; i < matrix.size(); i++) 
            for(int j = 0; j < matrix[0].size(); j++) 
                matrix[i][j] += min( { matrix[i-1][j], matrix[i-1][max(0, j-1)], matrix[i-1][ min((int)matrix.size() -1, j+1) ]  });
        
        
        return *min_element(begin(matrix[matrix.size() -1]), end(matrix[matrix.size() - 1]));
        
    }
};