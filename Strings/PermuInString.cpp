#include<iostream>
using namespace std;


bool isFreqSame(int freq1[],int freq2[]){
    for(int i=0;i<26;i++){
        if(freq1[i]!=freq2[i]){
            return false;
        }
    }
    return true ; 
}

//freq of char in s1 and no of char will be same 
bool permutationInString(string s1,string s2){
    int freq[26]={0} ; // as string can only contain lowercase letters so just 26 size of frequency array 

    for(int i=0;i<s1.length();i++){
        int indx=s1[i]-'a' ;
        freq[indx]++;
    }

    int windSize=s1.length() ;

    for(int i=0;i<s2.length();i++){
        int windIndx=0;
        int indx=i;
        
        int windFreq[26]={0} ;

        while(windIndx<windSize && indx<s2.length()){
            windFreq[s2[indx]-'a']++ ;
            windIndx++;
            indx++;
        }

        //check if windFreq and freq are same or not
        if(isFreqSame(freq,windFreq)){ //found permu in s2
              return true ;
        }
    }
    return false ;
}




bool permutationInString(string s1,string s2){
    int n=s1.length() ;
    int m=s2.length() ;

    if(n>m) return false ;

    int freq[256]={0} ;

    for(int i=0;i<n;i++){
        freq[s1[i]]++ ;
        freq[s2[i]]-- ;
    }

    for(int i=0;i<256;i++){
        if(freq[i]!=0) return false ;
    }

    for(int i=n;i<m;i++){
        freq[s2[i]]-- ;
        freq[s2[i-n]]++ ;

        bool flag=true ;
        for(int j=0;j<256;j++){
            if(freq[j]!=0){
                flag=false ;
                break ;
            }
        }
        if(flag) return true ;
    }

    return false ;
}