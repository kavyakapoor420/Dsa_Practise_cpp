
bool subsetRecur(int indx,int target,vector<int>& nums){

    //base case 
    if(target==0) return true ;

    if(indx==0) return nums[0]==target ; 

    bool exclude=subsetRecur(indx-1,target,nums) ; 


    // include only if valid 
    bool include=false ;

    if(nums[indx]<=target){
        include=subsetRecur(indx-1,target-nums[indx],nums) ; 
    }

    return include | exclude  ; 
}

bool subsetMemo(int indx,int target,vector<int>& nums,vector<vector<int>>& dp){
    if(target==0){
        return true ; 
    }
    if(indx==0){
        return nums[0]==target ; 
    }

    if(dp[indx][target]!=-1){
        return dp[indx][target] ;
    }

    bool exclude=subsetMemo(indx-1,target,nums,dp) ; 

    bool include=false ;

    if(nums[indx]<=target){
        include=subsetMemo(indx-1,target-nums[indx],nums,dp) ;
    }

    return dp[indx][target]=(include | exclude) ;
}

bool subsetTabu(int indx,int target,int n,vector<int>& nums){
    
    vector<vector<bool>> dp(n,vector<bool>(target+1,false)) ;

    // base case:sum=0 is always possible
    for(int i=0;i<n;i++){
        dp[i][0]=true ;  // target==0 
    }

    if(nums[0]<=target){
        dp[0][nums[0]]=true ; 
    }

    for(int i=1;i<n;i++){
        for(int sum=1;sum<=target;sum++){
            bool exclude=dp[i-1][sum] ;

            bool include=false ;

            if(nums[i]<=sum){
                include=dp[i-1][sum-nums[i]] ;
            }

            dp[i][sum]=include || exclude ;
        }
    }

    cout<<(dp[n-1][target] ? "YES" : "NO" ) ; 

}


int main(){
    vector<int> nums={1,3,4,5} ;

    int n=4;
    int target=7 ;
    cout<<subsetRecur(n-1,target,nums) ;


    vector<vector<bool>> dp(n,vector<bool>(target+1,false)) ;

    // base case:sum=0 is always possible
    for(int i=0;i<n;i++){
        dp[i][0]=true ;  // target==0 
    }

    if(nums[0]<=target){
        dp[0][nums[0]]=true ; 
    }

    for(int i=1;i<n;i++){
        for(int sum=1;sum<=target;sum++){
            bool exclude=dp[i-1][sum] ;

            bool include=false ;

            if(nums[i]<=sum){
                include=dp[i-1][sum-nums[i]] ;
            }

            dp[i][sum]=include || exclude ;
        }
    }

    cout<<(dp[n-1][target] ? "YES" : "NO" ) ; 
}
