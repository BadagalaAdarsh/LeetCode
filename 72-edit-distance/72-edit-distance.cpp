class Solution {
public:
    map<pair<int,int>, int> h;
  int minimum(int a, int b, int c) {
    int x = min(a,b);
    return min(x,c);
}

int helper(string word1, string word2, int m, int n){
    /*
    if (m == 0){
        return n;
    }
    
    if (n == 0){
        return m;
    }

    pair<int,int> temp = {m,n};
    
    if (h.find(temp) != h.end()){
        return h[temp];
    }

    
    if (word1[m-1] == word2[n-1]){
        return  h[temp] = helper(word1, word2, m - 1, n-1);
    }
    
    else 
        return h[temp] = 1 + minimum( helper(word1, word2, m - 1, n) , 
                      helper(word1, word2, m, n-1),
                      helper(word1, word2, m - 1, n-1)); */
    
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if (i == 0){
                dp[i][j] = j;
            }
            
            else if(j == 0){
                dp[i][j] = i;
            }
            
            else if(word1[i -1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            
            else {
                dp[i][j] = 1 + minimum(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }
    return dp[m][n];
}
    
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        return helper(word1, word2, m, n);
    }
};