class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
        if (matrix.size() == 0 ) return false;
        
        int start = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int end = rows * cols - 1;
        
        while(start <= end) {
            int mid = (start + end ) >> 1;
            
            if (matrix[mid / cols][mid % cols] == target) 
                return true;
            
            if(matrix[mid / cols][mid % cols] < target) 
                start = mid + 1;
            else 
                end = mid  - 1;
        }
        
        return false;
        
    }
};