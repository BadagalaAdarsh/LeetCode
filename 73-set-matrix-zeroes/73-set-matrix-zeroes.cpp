class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    bool col0 = false;
    int rows = matrix.size();
    int cols = matrix[0].size();

    for(int i = 0; i < rows; i++) {
        // check if first element is 0 that is top left 
        if (matrix[i][0] == 0) {
            col0 = true;
        }

        // then for rest of matrix if found 0 at any position mark the top right and left to 0
        // link to video solution is
        //https://www.youtube.com/watch?v=M65xBewcqcI&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=7

        for(int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    // now traverse the matrix in reverse order and set the matrix elements to 0 based on row and col
    // we are traversing the matrix in reverse because we are setting the elements to 0 based on row and col
    // and if we come from top if would change the top left one see the video for better explanation

    for(int i = rows - 1; i >= 0; i--){
        for(int j = cols - 1 ; j >= 1; j--) 
            if (matrix[i][0] == 0 || matrix[0][j] == 0) 
                matrix[i][j] = 0;

        if (col0) {
            matrix[i][0] = 0;
        }
    }
    }
    
};