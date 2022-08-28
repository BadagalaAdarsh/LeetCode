class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        map<int, priority_queue<int, vector<int>, greater<int>>> hashmap;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                hashmap[row - col].push(mat[row][col]);
            }
        }
        
        for(int row = 0; row < n; row++ ) {
            for(int col = 0; col < m; col++) {
                mat[row][col] = hashmap[row - col].top();
                hashmap[row - col].pop();
            }
        }
        
        return mat;
    }
};
