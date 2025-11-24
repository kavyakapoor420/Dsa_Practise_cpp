
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
