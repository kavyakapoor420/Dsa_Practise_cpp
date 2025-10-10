#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

void bfs(vector<vector<char>>& grid,int r,int c){
    int n=grid.size() ;
    int m=grid[0].size() ;

    queue<pair<int,int>> q;
    q.push({r,c}) ;
    grid[r][c]='0' ;

    int dirs[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    while(!q.empty()){
        auto [r,c]=q.front() ;
        q.pop() ;

        for(auto& d:dirs){
            int nRow=r+d[0];
            int nCol=c+d[1];

            if(nRow>0 && nCol>0 && nRow<n && nCol<m && grid[nRow][nCol]=='1'){
                grid[nRow][nCol]='0';
                q.push({nRow,nCol}) ; 
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid){
    if(grid.empty()) return 0 ;

    int cnt=0;
    int n=grid.size() ;
    int m=grid[0].size() ;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                cnt++ ;
                bfs(grid,i,j) ; 
            }
        }
    }

    return cnt; 
}

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of islands: " << numIslands(grid) << endl;
    return 0;
}