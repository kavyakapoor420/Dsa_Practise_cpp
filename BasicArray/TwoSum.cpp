#include<iostream>
#include<vector>
#include<unordered_map> 

using namespace std ;

//brute force
vector<int> twoSum(vector<int>& nums,int target){
    int n=nums.size() ;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                return {i,j} ;
            }
        }
    }

    return {} ;// no solution found
}


//hashmap

vector<int> twoSum(vector<int>& nums,int target){
    unordered_map<int,int> mp ;
    int n=nums.size() ;

    for(int i=0;i<n;i++){
        mp[nums[i]]=i; 
    }
    // for(auto it:nums){
    //     mp[it]++ ;
    // }

    //find the complement 
    for(int i=0;i<n;i++){
        int compliment=target-nums[i];
        if(mp.count(compliment) && mp[compliment]!=i){
            return {i,mp[compliment]} ;
        }
    }
    return {} ;// no solution found 
}
