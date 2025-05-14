#include<iostream>
#include<unordered_set>
using namespace std ;


int LongestSubstringWithoutReapChar(string s){
    int n=s.length() ;
    int l=0,r=0;
    int maxLen=0;
    int freq[256]={0} ;

    while(r<n){
        freq[s[r]]++ ;

        while(freq[s[r]]>1){
            freq[s[l]]-- ;
            l++ ;
        }

        maxLen=max(maxLen,r-l+1) ;
        r++ ;
    }

    return maxLen ;
}

int LongestSubstringWithoutReapChar(string s){
    int n=s.length();
    int maxLen=0;
    unordered_set<char> set ;
    int l=0,r=0;

    while(r<n){
        if(set.count(s[r])==0){
            set.insert(s[r]) ;
            maxLen=max(maxLen,r-l+1) ;
        }else{
            while(set.count(s[r])){
                set.erase(s[l]) ;
                l++;
            }
            set.insert(s[r]) ; 
        }
        r++; 
    }



    return maxLen ;
}