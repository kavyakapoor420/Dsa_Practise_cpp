// This problem's actual name, "Lexicographically Largest Palindromic Subsequence" is too long to fit into the page headline.

// You are given string s consisting of lowercase English letters only. Find its lexicographically largest palindromic subsequence.

// We'll call a non-empty string s[p1p2... pk] = sp1sp2... spk (1  ≤  p1 < p2 < ... < pk  ≤  |s|) a subsequence of string s = s1s2... s|s|, where |s| is the length of string s. For example, strings "abcb", "b" and "abacaba" are subsequences of string "abacaba".

// String x = x1x2... x|x| is lexicographically larger than string y = y1y2... y|y| if either |x| > |y| and x1 = y1, x2 = y2, ..., x|y| = y|y|, or there exists such number r (r < |x|, r < |y|) that x1 = y1, x2 = y2, ..., xr = yr and xr  +  1 > yr  +  1. Characters in the strings are compared according to their ASCII codes. For example, string "ranger" is lexicographically larger than string "racecar" and string "poster" is lexicographically larger than string "post".

// String s = s1s2... s|s| is a palindrome if it matches string rev(s) = s|s|s|s| - 1... s1. In other words, a string is a palindrome if it reads the same way from left to right and from right to left. For example, palindromic strings are "racecar", "refer" and "z".

// Input
// The only input line contains a non-empty string s consisting of lowercase English letters only. Its length does not exceed 10.

// Output
// Print the lexicographically largest palindromic subsequence of string s.

// Examples

// Input
// radar
// Output
// rr
// Input
// bowwowwow
// Output
// wwwww
// Input
// codeforces
// Output
// s
// Input
// mississipp
// Output
// ssss

#include<iostream>
#include<string>
#include<algorithm>
using namespace std ;

bool isPal(string str){
    int l=0,r=str.length()-1;

    while(l<r){
        if(str[l]!=str[r]){
            return false ;
        }
        l++;
        r--;
    }
    return true ;
}

int main(){
    string str ;
    cin>>str ;
    int n=str.length() ;
    string ans="";
    //generating all posssible subsequence using bitmask technique 
    for(int mask=1;mask<(1<<n);mask++){
        string sub ="";
        for(int i=0;i<n;i++){
            if(mask & (1<<n)){
                sub+=str[i] ;
            }
        }
        ans=max(ans,sub) ; //update if we find new  larger lexicographically string 
    }

    cout<<ans ;
    return 0;
}



#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPal(string str){
    int l = 0, r = str.length() - 1;
    while(l < r){
        if(str[l] != str[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main(){
    string str;
    cin >> str;
    int n = str.length();
    
    string ans = "";
    
    for(int mask = 1; mask < (1 << n); mask++){
        string sub = "";
        for(int i = 0; i < n; i++){
            if(mask & (1 << i)){
                sub += str[i];
            }
        }
        if(isPal(sub)){
            ans = max(ans, sub);
        }
    }
    
    cout << ans;
    return 0;
}



// Understanding Bitmasking for Subsequences
// Let's say we have a string:
// s = "abc"  // length = 3

// All subsequences of "abc" (excluding the empty one) are:
// a, b, c, ab, ac, bc, abc

// To generate these using bitmasking:

// Each bit in a binary number represents whether to include or exclude a character at that index.

// For string of length n, there are 2^n combinations.
// We loop from 1 to 2^n - 1 (we skip 0 to avoid empty subsequence).

//  Example with "abc" (n = 3)
// We loop from 1 to 7 (because 2³ = 8, but skip 0).

// Now, let’s see what each bitmask gives:

// | Mask (Binary) | Decimal | Included bits | Subsequence |
// | ------------- | ------- | ------------- | ----------- |
// | 001           | 1       | --- --c       | `c`         |
// | 010           | 2       | --- -b-       | `b`         |
// | 011           | 3       | --- -bc       | `bc`        |
// | 100           | 4       | --a---        | `a`         |
// | 101           | 5       | --a--c        | `ac`        |
// | 110           | 6       | --ab--        | `ab`        |
// | 111           | 7       | --abc-        | `abc`       |


// for (int mask = 1; mask < (1 << n); ++mask) {
//     string sub = "";
//     for (int i = 0; i < n; ++i) {
//         if (mask & (1 << i)) {
//             sub += s[i];
//         }
//     }
//     // check sub
// }



// (1 << i) creates a number with only the i-th bit set.

// mask & (1 << i) checks if the i-th character should be included in the subsequence.

//  Let's Dry Run One Iteration
// Suppose mask = 5 which is 101 in binary:

// for (int i = 0; i < 3; ++i) {
//     if (mask & (1 << i)) {
//         sub += s[i];
//     }
// }



// Breakdown:

// i = 0: 1 << 0 = 001, 101 & 001 = 001 → include s[0] = 'a'

// i = 1: 1 << 1 = 010, 101 & 010 = 000 → skip

// i = 2: 1 << 2 = 100, 101 & 100 = 100 → include s[2] = 'c'

// So, sub = "ac"

// ✅ How We Use This
// After generating the subsequence using the mask, we:

// Check if the subsequence is a palindrome.

// If it is, compare it with the current best and keep the lexicographically larger one.

// 🔠 Lexicographical Order Example
// If we had two palindromic subsequences "aba" and "aca", "aca" is larger because:

// 'a' == 'a', 'b' < 'c' → so "aca" > "aba"


