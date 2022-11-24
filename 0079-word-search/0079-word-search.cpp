class Solution {
private:
    vector<pair<int,int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool isInside(int row, int col, int n, int m) {
        return 0 <= row && row < n && 0 <= col && col < m;
    }
    
    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int index) {
        
        if(index == word.size()) return true;
        
        if(!isInside(i,j, board.size(), board[0].size())) return false;
        
        if(board[i][j] != word[index]) return false;
        
        // to avoid repeated search
        // 
        board[i][j] = '*';
        
        for(pair<int,int> dir: directions) {
                      
            if(dfs(i + dir.first, j + dir.second, board, word, index + 1)) return true;
        }
        
        // backtracking step
        board[i][j] = word[index];
        return false;
    }

    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                
                if(dfs(i, j, board, word, 0) )
                    return true;
            }
        }
        
        return false;       
        
    }
};