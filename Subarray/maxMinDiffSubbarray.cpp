// 📄 Extracted Problem Statement: Stacking Money
// 🧾 Problem Description:
// After a tiring fight against the Mad Titan, Wanda and Vision settled down to a normal life. Now, they have to worry about trivial things like money.
// One day, Vision was stacking coins.
// He made N different stacks of coins represented in the form of an integer array A, where each stack had A[i] coins.

// 🧠 Vision asked Wanda the following question:
// Find the sum of the difference of maximum and minimum number of coins over all subarrays of A.

// 📌 Problem Constraints:
// 1
// ≤
// 𝑁
// ≤
// 10
// 5
// 1≤N≤10 
// 5
 

// 1
// ≤
// 𝐴
// [
// 𝑖
// ]
// ≤
// 10
// 9
// 1≤A[i]≤10 
// 9
 

// 🔢 Input Format:
// The first argument is the integer array A.

// 📤 Output Format:
// Return a single long integer denoting the value Vision asked for.


#include<iostream>
#include<vector>
#include<climits>

using namespace std ;

long long stackingMoneyBrute(vector<int>& arr){
    int n=arr.size() ;

    long long sum=0;

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int mini=INT_MAX ;
            int maxi=INT_MIN ;

            for(int k=i;k<=j;k++){
                mini=min(mini,arr[k]) ;
                maxi=max(maxi,arr[k]) ; 
            }

            sum+=(maxi-mini) ; 
        }
    }
    return sum ; 
}

long long stackingMoneyOptimal(vector<int>& arr){
    int n=arr.size();

    vector<int> prevGreater(n) ;
    vector<int> prevSmaller(n) ;
    vector<int> nextSmaller(n) ;
    vector<int> nextGreater(n) ;

    stack<int> st ;

    //previous greater nikalo 
    for(int i=0;i<n;i++){
        while(st.empty() && arr[st.top()]<arr[i]){
            st.pop() ;
        }
        prevGreater[i]=st.empty() ? -1 : st.top() ; 
        st.push(i) ; 
    }
    // st.clear();

    while(!st.empty()) st.pop() ;

    // next greater 
    for(int i=n-1;i>=0;i--){
        while(st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }
        nextGreater[i]=st.empty() ? -1 : st.top() ;
        st.push(i) ;
    }

    while(!st.empty()) st.pop() ; 

    //previous smaller 
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop() ; 
        }
        prevSmaller[i]=st.empty() ? -1 : st.top() ;  
        st.push(i) ; 
    }
    // next smaller 
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>arr[i]){
            st.pop() ; 
        }
        nextSmaller[i]=st.empty() ? n : st.top() ; 
        st.push(i) ;
    }

    long long maxSum=0;
    long long minSum=0;

    for(int i=0;i<n;i++){
        long long left=i-prevGreater[i];
        long long right=nextGreater[i]-i ;
        
        maxSum+=(long long)arr[i]*left*right ;
    }

    for(int i=0;i<n;i++){
        long long left=i-prevSmaller[i];
        long long right=nextSmaller[i]-i ;

        minSum+=(long long)arr[i]*left*right ;
    }

    return maxSum-minSum ; 
}


int main(){

}


// n = 3
// A = [1, 2, 3]


// Brute Force: 4
// Optimal: 4


// a=[1,1,1]
// ans=0 