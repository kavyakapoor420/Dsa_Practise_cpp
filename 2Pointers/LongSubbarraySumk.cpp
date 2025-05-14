//return length of longest subarray wuth sum k

#include<iostream>
#include<vector>

using namespace std ;

//brute force approach 
//find all possible subarrays and check if their sum is equal to k 
//time complexity is O(n^2) and space complexity is O(1)
int longSubarrayWithSumk(vector<int> &arr,int k){
        int n=arr.size();

        int maxLen=0;

        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum=sum+arr[j];

                if(sum<=k){
                    maxLen=max(maxLen,j-i+1) ;

                }else if(sum>k){ // slightly optimized
                    break ;
                }
            }
        }

        return maxLen;
}


//sliding window approach
int longSubarrayWithSumk(vector<int> &arr,int k){
        int n=arr.size();

        int maxLen=0;
        int sum=0;
        int start=0;

        for(int end=0;end<n;end++){
            sum+=arr[end];

            while(sum>k){
                sum-=arr[start];
                start++;
            }

            maxLen=max(maxLen,end-start+1);
        }

        return maxLen;


        int n=arr.size() ;

        int l=0,r=0,sum=0;
        int maxLen=0;

        while(r<n){
            sum=sum+arr[r];

            while(sum>k){  // not a valid window so shrink size of it 
                sum=sum-arr[l];
                l=l+1;
            }

            if(sum<=k){
                maxLen=max(maxLen,r-l+1) ;
            }
            r=r+1;
        }

        return maxLen ;
}

int main(){

      vector<int> arr={2,5,1,7,10} ;
      int k=14;

      cout<< longSubarrayWithSumk(arr,k) ;
}