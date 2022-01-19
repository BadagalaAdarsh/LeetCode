class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int sizeOfTriangle = triangle.size();
        
        vector<int> minLength(triangle.back());
        
        for(int layer = sizeOfTriangle - 2; layer >= 0; layer--) {
            
            for(int index = 0; index <= layer; index++) {
                
                minLength[index] = min( minLength[index], minLength[index + 1]) + triangle[layer][index];
            }
        }
        
        return minLength[0];
    }
};