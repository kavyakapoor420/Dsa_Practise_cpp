// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.




#include<iostream>
#include<vector>

using namespace std ;

//brute force

int subarraySumk(vector<int>& arr,int k){
    
     int n=arr.size() ;
     int cntSubarraySumk=0;

     for(int i=0;i<n;i++){

        int sum=0;
        for(int j=i;j<n;j++){
            sum=sum+arr[j];
            if(sum==k){
                cntSubarraySumk++;
            }
        }
     }
     return cntSubarraySumk;

}