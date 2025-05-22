// Set Matrix Zeroes
// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]


#include<iostream>
#include<vector>
using namespace std ;

void makeRowZero(vector<int>& row, int colSize) {
    for (int i = 0; i < colSize; i++) {
        row[i] = 0;
    }
}

void makeColZero(vector<vector<int>>& matrix, int colIndex, int rowSize) {
    for (int i = 0; i < rowSize; i++) {
        matrix[i][colIndex] = 0;
    }
}

void setZeroes(vector<vector<int>>& matrix) {
    int rowSize = matrix.size();
    int colSize = matrix[0].size();
    vector<pair<int, int>> zerosPos;

    // First pass: record all positions with zeros
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if (matrix[i][j] == 0) {
                zerosPos.push_back({i, j});
            }
        }
    }

    // Second pass: zero out rows and columns
    for (auto& pos : zerosPos) {
        makeRowZero(matrix[pos.first], colSize);
        makeColZero(matrix, pos.second, rowSize);
    }
}

// Hint 1: Understand the Problem Carefully
// You’re given a matrix. If any cell is 0, you need to set its entire row and entire column to 0.
// This means a single zero can affect multiple values across the matrix.

// The tricky part? You must do this in-place (i.e., without returning a new matrix).

// Hint 2: Why You Can’t Modify the Matrix Immediately
// Suppose you find a 0 and instantly set the row and column to 0.
// Problem: You might accidentally erase information about other zeroes that you haven’t processed yet!

// For example, if you change a 1 to a 0, your code may think it was originally 0, and wrongly zero out more rows/columns.

// Hint 3: First Pass – Collect All Zero Positions
// To avoid the above problem, first scan the matrix and record all positions (i, j) where matrix[i][j] == 0.
// Store these positions in a list. Don't modify the matrix yet.

// This way, you preserve the original state of the matrix and avoid false positives.

// Hint 4: Second Pass – Zero Out Rows and Columns
// Now go through each recorded zero position (i, j).
// Set all elements in row i to 0

// Set all elements in column j to 0

// This can be done with helper functions that loop through the row and column.

// Hint 5: Time and Space Complexity
// 🕒 Time Complexity:
// First pass to scan the matrix: O(m * n)

// Second pass: for each zero, set its row and column: O(k * (m + n))

// In worst-case (all elements are zero), this becomes: O((m * n) * (m + n))

