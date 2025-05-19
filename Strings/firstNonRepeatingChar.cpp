//First non-repeating character of given string
//Given a string s of lowercase English letters, the task is to find the first non-repeating character. If there is no such character, return '$'.

// Examples: 

// Input: s = "geeksforgeeks"
// Output: 'f'
// Explanation: 'f' is the first character in the string which does not repeat.

// Input: s = "racecar"
// Output: 'e'
// Explanation: 'e' is the only character in the string which does not repeat.

// Input: "aabbccc"
// Output: '$'
// Explanation: All the characters in the given string are repeating.

#include<iostream>
using namespace std ;

//burte force approach 
char firstNonRepeating(string& str){
    int n=str.length() ;

    for(int i=0;i<n;i++){
        bool foundRepeatingChar=false ;
        for(int j=0;j<n;j++){
            if(i!=j && str[i]==str[j]){
                foundRepeatingChar=true ;
            }
        }
        if(!foundRepeatingChar) return str[i] ;
    }
    return '$' ;
}

int main (){
     string str="geekforgeeks" ;// f is the answer
    cout<<firstNonRepeating(str) ;

}

char firstNonRepeatingChar(string& str){
    int n=str.length() ;
    vector<int> freqArray(26,0) ;
    
    for(char ch:str){
        freqArray[ch-'a']++ ;
    }

    //find first char with frequency 1
    for(char ch:str){
        if(freqArray[ch-'a']==1){
            return ch ;
        }
    }
  return '$' ;
}





