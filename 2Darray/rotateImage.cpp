// You are given an n x n 2D matrix representing an image,
//  rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to 
// modify the input 2D matrix directly. DO NOT allocate another 2D matrix 
// and do the rotation.

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]

// class Solution {
    public:
       void transpose(vector<vector<int>>& matrix) {
            for (int i = 0; i < matrix.size(); ++i) {
                for (int j = i; j < matrix[0].size(); ++j) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }
    
        void reverseRows(vector<vector<int>>& matrix) {
            for (int r = 0; r < matrix.size(); ++r) {
                int left = 0;
                int right = matrix.size() - 1;
    
                while (left < right) {
                    int temp = matrix[r][left];
                    matrix[r][left] = matrix[r][right];
                    matrix[r][right] = temp;
    
                    left++;
                    right--;
                }
            }
        }
        void rotate(vector<vector<int>>& matrix) {
             transpose(matrix);
            reverseRows(matrix);
        }
    };