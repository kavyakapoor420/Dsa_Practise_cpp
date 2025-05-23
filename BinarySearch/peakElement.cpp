#include<iostream>
#include<vector>
using namespace std ;


int peakEle(vector<int>& nums){
    //we have to return index of peak ele 
    
    int n=nums.size() ;
    if(n==1) return 0 ; //if single ele in array so that will be peak ele 
    //check if oth/n-1th ele is peak ele 
    if(nums[0]>nums[1]) return 0 ; //just compare 0th with first ele as no ele on left of 0th ele ie nums[-1]
    if(nums[n-1]>nums[n-2]) return n-1;

    int s=0,e=n-1;

    while(s<=e){
       int mid=s+(e-s)/2;
       //if mid ele is peak ele 
       if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
          return mid ;
       }
       //peak ele lies on left half of array 
       else if(nums[mid]<nums[mid-1]){ 
          e=mid-1;
       }
       else if(nums[mid]<nums[mid+1]){
        s=mid+1;
       }
    }
    return -1; 
}