// 350. Intersection of Two Arrays II
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.

#include<iostream>
#include<vector>
using namespace std ;

//approach1 sort both array and traverse using 2 pointer and compare ele and check for duplicate ele
vector<int> intersection(vector<int>& nums1,vector<int>& nums2){
        vector<int> ans ;
        int n=nums1.size() ;
        int m=nums2.size() ;

        int i=0; //will traverse on first array 
        int j=0; //will traverse on second array 
        
        sort(nums1.begin(),nums1.end()) ;
        sort(nums2.begin(),nums2.end()) ; 
       while(i<n && j<m){
         if(nums1[i]<nums2[j]){
            i++;
         }
         else if(nums1[i]>nums2[j]){
            j++;
         }
         else{
            ans.push_back(nums1[i]) ;
            i++;
            j++;
         }
       }
       return ans ;
}

//approach2 using hashmap store freq of each ele of first array in map and iterate on 2nd array then check for intersection
vector<int> intersection(vector<int>& nums1,vector<int>& nums2){
    vector<int> ans ;
    int n=nums1.size() ;
    int m=nums2.size() ;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[nums1[i]]++ ;
    }
    for(int i=0;i<m;i++){
        int ele=nums2[i];
        if(mp.find(ele)!=mp.end() && mp[ele]-- > 0 ){
            ans.push_back(nums2[i]) ;
        }
    }
    return ans ;    
}