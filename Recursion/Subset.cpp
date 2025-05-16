// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order. 

#include<iostream>
#include<vector>
using namespace std ;

void solve(int index, int arr[], int n, vector<int> &ds, vector<vector<int>> &ans) {
    if (index == n) {
        ans.push_back(ds);
        return;
    }
    // Exclude the current element
    solve(index + 1, arr, n, ds, ans);
    
    // Include the current element
    ds.push_back(arr[index]);
    solve(index + 1, arr, n, ds, ans);
    
    // Backtrack
    ds.pop_back();
}
vector<vector<int>> subsets(int arr[], int n) {
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, arr, n, ds, ans);
    return ans;
}
int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> result = subsets(arr, n);
    
    cout << "Subsets are: " << endl;
    for (const auto &subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}



void solve(int indx,vector<int>& nums,int n,vector<int>& output ,vector<vector<int>>& ans){
    if(indx>=n){  //base case 
        ans.push_back(output) ;
        return  ;
    }

    //exclude the current element 
    solve(indx+1,nums,n,output,ans) ;

    //include the current element 
    output.push_back(nums[indx]) ;
    solve(indx+1,nums,n,output,ans) ;

    //backtrack 
    output.pop_back() ;
}
vector<vector<int>> subset(vector<int>& nums,int n){
    vector<vector<int>> ans ;
    vector<int> output ;

    solve(0,nums,n,output,ans) ;
    return ans ;
}