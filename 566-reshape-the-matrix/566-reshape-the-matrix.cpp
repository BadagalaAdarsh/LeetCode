class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int m = mat.size(), n = mat[0].size(), total = m * n;
        if (r * c != total) return mat;
        
        vector<vector<int>> answer(r, vector<int>(c));
        
        for(int i = 0; i < total; i++){
            answer[i/c][i%c] = mat[i/n][i%n];
        }
        
        return answer;
    }
};