
string  printLcs (){
    string s1="abcde";
    string s2="ace" ;

    int n=s1.size() ;
    int m=s2.size() ;

    vector<vector<int>> dp(n,vector<int>(m,0));

    // build up dp table 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(s1[i]==s2[j]){
                if(i==0 || j==0){
                    dp[i][j]=1; 
                }else{
                    dp[i][j]=1+dp[i-1][j-1];
                }
            }else{

                int up=(i>0 ? dp[i-1][j] : 0) ;
                int left=(j>0 ? dp[i][j-1] : 0) ; 

                dp[i][j]=max(up,left) ; 
            }
        }
    }

    int len=dp[n-1][m-1]; // lenght of lcs 

    string ans="";

    for(int i=0;i<len;i++){
        ans+="$" ; // initiliaze with $ 
    }

    int i=n-1;
    int j=m-1;
    int k=len-1;

    //backTrack to build lcs 
    while(i>=0 && j>=0){
        if(s1[i]==s2[j]){
            ans[k]=s1[i];
            i--;
            j--;
            k--;
        }else{
            int up=(i>0 ? dp[i-1][j] : 0 );
            int left=(j>0 ? dp[i][j-1] : 0) ; 

            if(up>=left ) i--;
            else j--; 
        }
    }

    cout<<"LCS"<<ans ;

    return ans ; 
}
