
// longest increasing  subsequence  = LCS(nums,sorted(nums)+ hashest approach unqiue elemneted stpre d)

int LCS(vector<int>& a,vector<int>& b){
    int n=a.size() ;
    int m=b.size() ;

    vector<vector<int>> dp(n+1,vector<int>(m+1,0)) ;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]) ; 
            }
        }
    }

    return dp[n][m];
}

int main(){

    vector<int> nums={10,9,2,5,3,7,101,18} ;

    set<int> st; 
    for(int x:nums){
        st.insert(x) ; 
    }

    vector<int> sortedNums(st.begin(),st.end()) ;

    int lisLength=LCS(nums,sortedNums) ; 

    cout<<lisLength ; 

}




class Solution {
public:
    
    // int solveRecur(vector<int>& nums,int i,int prev){
    //     if(i>=nums.size()) return 0 ;

    //     int notTake=solveRecur(nums,i+1,prev) ;
    //     int take=0;
    //     if(nums[i]>prev){
    //         take=1+solveRecur(nums,i+1,nums[i]) ; 
    //     }

    //     return max(take,notTake) ; 
    // }

    int solveMemo(vector<int>& nums,int i, int prev_i, vector<vector<int>>& dp){
        if(i>=nums.size()) return 0 ;

        if(dp[i][prev_i+1]!=-1){
            return dp[i][prev_i +1 ] ;
        }

        int notTake=solveMemo(nums,i+1,prev_i,dp);
        int take=0;

        if(prev_i==-1 || nums[i]>nums[prev_i]){
            // try picking current element if no previuso element is chosen
            // or current>nums[prev_i] 
            take=1+solveMemo(nums,i+1,i,dp) ;
        }

        return dp[i][prev_i+1]=max(take,notTake) ;
    }

    int lengthOfLIS(vector<int>& nums) {

        vector<vector<int>> dp; 
        dp.resize(nums.size(),vector<int>(1+nums.size(),-1));
        return solveMemo(nums,0,-1,dp); 

        // return solveRecur(nums,0,INT_MIN) ; 

        //tabulation 
        // int ans=1;
        // int n=nums.size() ;

        // vector<int> dp(n,1) ;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]>nums[j]){
        //             dp[i]=max(dp[i],dp[j]+1) ; 
        //             ans=max(ans,dp[i]) ; 
        //         }
        //     }
        // }
        // return ans ; 
        
        // int n=nums.size() ;

        // vector<int> dp(n,1) ;

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]>nums[j] && dp[i]<dp[j]+1){
        //             dp[i]=dp[j]+1;
        //         }
        //     }
        // }

        // return *max_element(dp.begin(),dp.end()) ;


    }
};
