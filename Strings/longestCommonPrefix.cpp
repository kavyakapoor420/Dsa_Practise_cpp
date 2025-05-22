// 14. Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

#include<iostream>
using namespace std ;

string  longestCommonPrefix(vector<string>& strs){
    if(strs.empty()) return "";

    string ans="";
    int a=strs.size();
    string n=strs[0],m=strs[a-1] ;

    for(int i=0;i<n.size();i++){
      if(n[i]==m[i]) ans+=n[i];
      else break ;
    }

    return ans ;
}



// Intuition
// To find the longest common prefix among an array of strings, we can compare the characters of all strings from left to right until we encounter a mismatch. The common prefix will be the characters that are the same for all strings until the first mismatch.

// Approach
// If the input array strs is empty, return an empty string because there is no common prefix.

// Initialize a variable prefix with an initial value equal to the first string in the array strs[0].

// Iterate through the rest of the strings in the array strs starting from the second string (index 1).

// For each string in the array, compare its characters with the characters of the prefix string.

// While comparing, if we find a mismatch between the characters or if the prefix becomes empty, return the current value of prefix as the longest common prefix.

// After iterating through all strings, return the final value of prefix as the longest common prefix.

