#include<iostream>
using namespace std ;
 
int miniMoves(string str){
    
    int miniMoves=0;
    int balance=0;
    
    for(char ch:str){
        if(ch=='('){
            balance++;
        }else{          //closing bracket found 
            balance--;
        }
        
        if(balance<0){
            miniMoves++;
            balance=0;
        }
    }
    return miniMoves ;  
}
 
int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n ;
        string str ;
        cin>>str ;
        
        cout<<miniMoves(str)<<endl ;
        
    }
    return 0 ; 
}


// Approach 2: Count Unmatched Closing Brackets
// 🧠 Idea:
// Traverse the string from left to right.

// Maintain a balance (similar to previous), but this time:

// +1 for '('

// -1 for ')'

// If balance goes negative, it means we had more ) than ( up to that point — i.e., an unmatched closing bracket.

// Every time balance < 0, increment neededMoves, and reset balance to 0 because we imagine we've "moved" that unmatched ) to the end or beginning.

