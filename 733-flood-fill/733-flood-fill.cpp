class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] != newColor) 
            dfs(image, sr, sc, image[sr][sc], newColor);
        
        return image;
    }
    
private:
    void dfs(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {
        
        int n = image.size(), m = image[0].size();
        
        if(isNotOk(i, j, n, m, oldColor, newColor, image))
            return;
        
        image[i][j] = newColor;
        dfs(image, i + 1, j, oldColor, newColor);
        dfs(image, i - 1, j, oldColor, newColor);
        dfs(image, i, j + 1, oldColor, newColor);
        dfs(image, i, j - 1, oldColor, newColor);
        
    }
    
    bool isNotOk(int i, int j, int n, int m, int oldColor, int newColor, vector<vector<int>>& image){
        
        if(i >= n || i < 0 || j >= m || j < 0 )
            return true;
        
        if(image[i][j] != oldColor || image[i][j] == newColor) 
            return true;
        
        return false;
    }
};