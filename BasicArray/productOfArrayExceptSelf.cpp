// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// You must write an algorithm that runs in O(n) time and without using the division operation.

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]


#include<iostream>
#include<vector>
using namespace std ;

vector<int> productExceptSelf(vector<int>& nums){
    vector<int> ans ;
    int n=nums.size() ;

    for(int i=0;i<n;i++){
      int prod=1;
      for(int j=0;j<n;j++){
        if(i!=j){
            prod=prod*nums[j] ;
        }
      }
      ans.push_back(prod) ;
    }

    return ans ; 

    //second approach 

    vector<int> prefix(n) ;
    vector<int> suffix(n) ;

    prefix[0]=nums[0];
    suffix[n-1]=nums[n-1] ;

    for(int i=1;i<n;i++){
      prefix[i]=prefix[i]*nums[i];
    }

    for(int i=n-2;i>0;i--){
        suffix[i]=suffix[i]*nums[n-i-1] ;
    }

    for(int i=0;i<n;i++){
        int res=prefix[i]*suffix[i] ;
        ans.push_back(res) ; 
    }

    return ans;
}