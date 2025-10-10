#include<iostream>
#include<vector>
using namespace std ;

void dfs(vector<vector<char>>& grid,int r,int c){
    int n=grid.size() ;
    int m=grid[0].size() ;


    if(r<0 || c<0 || r>=n || c>=m || grid[r][c]=='0') return ; 

    grid[r][c]='0';

    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1} ;

    for(int i=0;i<4;i++){
       int nRow=r+delRow[i];
       int nCol=c+delRow[i];

       dfs(grid,nRow,nCol) ; 

    }   
}

int numIslands(vector<vector<char>>& grid){
    if(grid.empty()) return 0 ;

    int n=grid.size() ;
    int m=grid[0].size() ;

    int cnt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(grid[i][j]=='1'){
            cnt++; 
            dfs(grid,i,j) ; 
           }
        }
    }
    return cnt ; 
}

int main(){
vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of islands: " << numIslands(grid) << endl;
    return 0;
}