#include<iostream>
using namespace std ;


int power(int a,int b){
    if(a==0) return 0 ;

    return (b==0) ? 1 : a * power(a, b - 1);
}
//optimized
int powerOptimized(int a,int b){
    if(a==0) return 1 ;
    int halfPower=powerOptimized(a,b/2) ;

    int halfPowerSquare=halfPower*halfPower;
    if(b%2==0){
        halfPowerSquare=a*halfPowerSquare ;
    }
    return halfPowerSquare ;
}

bool isSorted(int arr[],int i){
    int n=sizeof(arr)/sizeof(arr[0]) ;
    if(i==n-1) return true  ;
    if(arr[i]>arr[i+1]) return false ;

    return isSorted(arr,i+1) ; 
}