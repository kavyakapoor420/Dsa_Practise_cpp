#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std ;

//first approach using map
int singleNumer(vector<int>& nums){
    int n=nums.size() ;
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[nums[i]]++;
    }
    for(auto it:mp){
        if(it.second==1){
            return it.first ;
        }
    }
    return -1;
}
//second approach using sorting -> so that similar elements will come adjacent to each other
int singleNum(vector<int>& nums){
    int n=nums.size() ;

    for(int i=1;i<n;i++){
        if(nums[i]!=nums[n-1]){
            return nums[i-1] ;
        }
    }
    return nums[nums.size()-1]  ;
}
//third approach using bitwise operator all duplicates will cancel each other and then 0^singleNum=singlenNum
int singleNum(vector<int>nums){
    int n=nums.size() ;
    int single=0;

    for(int i=0;i<n;i++){
        single=single^nums[i];
    }
    return single ;
}