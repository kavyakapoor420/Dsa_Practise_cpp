#include<iostream>
#include<vector>

using namespace std ;

int recur(int indx,int w,int wt[],int val[]){
    if(indx==0){
        if(wt[0]<w){
            return val[0];
        }

        return 0 ;
    }
    int notTake=0+recur(indx-1,w,wt,val);
    
    int take=-1e9 ;

    if(wt[indx]<=w){
        take=val[indx]+recur(indx-1,w,wt,val) ; 
    }

    return max(take,notTake) ; 
}


int memo(int indx,int w,int wt[],int val[],vector<vector<int>>& dp){
    if(indx==0){
        if(wt[0]<=w){
            return val[0];
        }

        return 0 ; 
    }

    if(dp[indx][w]!=-1){
        return dp[indx][w];
    }

    int notTake=memo(indx-1,w,wt,val,dp);

    int take=-1e9;

    if(wt[indx]<=w){
        take=val[indx]+memo(indx-1,w-wt[indx],wt,val,dp) ; 
    }

    return dp[indx][w]=max(take,notTake);

}

int tabu(){

   
}


int main() {


    int wt[]={1,3,4,5} ;
    int val[]={1,4,5,7} ;

    int n=4;
    int W=7;

    cout<<recur(n-1,W,wt,val) ; 


     vector<vector<int>> dp(n,vector<int>(w+1,0)) ; 

     //base case for indx=0;

     for(int w=0;w<=W;w++){
        if(wt[0]<=W){
            dp[0][w]=val[0];
        }else{
            dp[0][w]=0;
        }
     }

     // build table 

     for(int indx=1;indx<n;indx++){
        for(int w=0;w<=W;w++){
            int notTake=dp[indx-1][w];

            int take=-1e9 ;

            if(wt[indx]<=w){
                take=val[indx]+dp[indx-1][w-wt[indx]] ; 
            }

            dp[indx][w]=max(take,notTake) ; 
        }
     }
     cout<<dp[n-1][W] ; 
}



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
