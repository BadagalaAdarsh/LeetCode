class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
    int n = matrix.size();

    // first we need to transpose the matrix in-place
    for(int i = 0;  i < n; i++) {
        for(int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // then we need to reverse the rows
    for(int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
    }
};
