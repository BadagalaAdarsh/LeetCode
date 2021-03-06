class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int H = matrix.size();
        
        if(H == 0 || matrix[0].size() == 0){
            return 0;
        }
        int W = matrix[0].size();
        int answer = 0;
        vector<vector<int>> dp(H, vector<int>(W));
        
        for(int row = 0; row < H; row++){
            for(int col = 0; col < W; col++){
                
                if (matrix[row][col] == '1'){
                    dp[row][col] = 1;
                    
                    if (row > 0 && col > 0){                        
                        dp[row][col] += min({dp[row-1][col],dp[row-1][col-1],dp[row][col-1]});
                    }
                    answer = max(answer,dp[row][col]);
                }
            }
        }
        
        return answer*answer;
    }
};