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


