// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], 
//word = "ABCCED"
// Output: true
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],
//  word = "SEE"
// Output: true

#include<iostream>
#include<vector>
using namespace std ;


bool search(vector<vector<char>>& board,string word,int i,int j, int indx){
    // Base case: If the entire word has been found, return true
    if(indx==word.length()) return true ;
    // Check for out-of-bounds or mismatched characters
    if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=word[indx] )  return false ;
    //mark the current cell as visited
    board[i][j]='*' ;
    //define the possible directions to move in the maze
    int nRow[4]={-1,1,0,0} ;
    int nCol[4]={0,0,-1,1} ;
    // Recursively search in all four directions from the current cell
    for(int k=0;k<4;k++){
        bool ans=search(board,word,i+nRow[k],j+nCol[k],indx+1) ;
        if(ans==true){
            return ans ;  //if word is found return true 
        }
    }
    //backtrack restore the original character in board 
    board[i][j]=word[indx] ;
    return false ;
}

bool exist(vector<vector<char>>& board, string word) {
    
    int n=board.size() ;
    int m=board[0].size() ;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
             // If the current cell matches the first character of the word, start searching
            if(board[i][j]==word[0]){
                bool ans=search(board,word,i,j,0) ;

                if(ans){
                    return ans ; // If the word is found, return true
                }
            }
        }
    }
  return false ; // If the word is not found in the maze, return false
}