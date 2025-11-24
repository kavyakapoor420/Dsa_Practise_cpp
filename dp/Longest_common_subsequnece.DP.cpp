
int lcsRec(int i,int j,string& s1,string& s2){

    if(i<0 || j<0) return 0 ;

    if(s1[i]==s2[j]){
        return 1+lcsRec(i-1,j-1,s1,s2) ; 
    }

    // char dont macth exclude one 

    return 0+max(lcsRec(i-1,j,s1,s2),
                  lcsRec(i,j-1,s1,s2)) ;
}

int lcsMemo(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
    
    if(i<0 || j<0) return 0 ;

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(s1[i]==s2[j]){
        return dp[i][j]=1+lcsMemo(i-1,j-1,s1,s2,dp) ;
    }

    return dp[i][j]=max(lcsMemo(i-1,j,s1,s2,dp),
                        lcsMemo(i,j-1,s1,s2,dp))  ;

}




int main(){
    string s1="abcde" ;
    string s2="ace" ;

    int n=s1.size();
    int m=s2.size() ;

    cout<<lcsRec(n-1,m-1,s1,s2) ;

    // tabulation 

    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){

            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1] ;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]) ; 
            }
        }
    }
    cout<<dp[n][m]; 

}
