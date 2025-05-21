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


#include <iostream>
#include <set>
using namespace std;

int main() {
    string username;
    cin >> username;
    
    set<char> unique_chars;
    for (char c : username) {
        unique_chars.insert(c);
    }

    if (unique_chars.size() % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    string username;
    cin >> username;

    int freq[26] = {0}; // to store frequency of characters

    for (char c : username) {
        int index = c - 'a';
        freq[index] = 1; // mark as seen
    }

    int distinct = 0;
    for (int i = 0; i < 26; i++) {
        distinct += freq[i];
    }

    if (distinct % 2 == 0)
        cout << "CHAT WITH HER!" << endl;
    else
        cout << "IGNORE HIM!" <<endl;

    return 0;
}
