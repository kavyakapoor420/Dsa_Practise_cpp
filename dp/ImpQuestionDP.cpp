// longest common subsequnce 
class Solution {
public:

   int solveMemo(string& s1, string& s2, int i, int j, vector<vector<int>>& dp){
    if(i >= s1.size() || j >= s2.size()){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + solveMemo(s1, s2, i+1, j+1, dp);
    }
    else{
        return dp[i][j] = max(
            solveMemo(s1, s2, i+1, j, dp),
            solveMemo(s1, s2, i, j+1, dp)
        );
    }
}

    int longestCommonSubsequence(string text1, string text2) {

        
        int m=text1.size() ;
        int n=text2.length() ;

        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solveMemo(text1,text2,0,0,dp) ;

      // tabulation code 

        vector<vector<int>> dp(m+1,vector<int>(n+1)) ;

        for(int i=0;i<=m;i++) dp[i][0]=0;

        for(int j=0;j<=n;j++) dp[0][j]=0;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){

                if(text1[i-1]==text2[j-1]){ // if charc matches in both
                    dp[i][j]=1+dp[i-1][j-1];

                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]) ;
                }
            }
        }
        return dp[m][n];
    }
};



// edit distance  Minimum indertion or deletion or replace charcater to conert string1 to string2 

int minDistance(string s,string t){

    int n=s.size() ;
    int m=t.size() ;

    for(int i=0;i<=m;i++) dp[i][0]=i;
    for(int j=0;j<=n;j++) dp[0][j]=j;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            
            if(s[i-1]==t[j-1]){
                dp[i][j]=0+dp[i-1][j-1];
            }else{
                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]}) ; // insert update delet character 
            }
        }
    }
    return dp[n][m];

    // to print LCS first build up Dp table then backtrcaking for get LCS 
    int i=n;
    int j=m;
    string lcs="" ;

    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            lcs.push_back(s[i-1]);
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(lcs.begin(),lcs.end()) ;
    return lcs; 

}


// buy sell stock 


int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(prices[j] - prices[i] > maxProfit){
                    maxProfit = prices[j] - prices[i];
                }
            }
        }
        return maxProfit;
   }
   
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }

        return maxProfit;
    }
};

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            } else if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        return profit;
    }
};
