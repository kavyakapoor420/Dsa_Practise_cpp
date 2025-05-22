bool exist(vector<vector<char>>& board,string word){
    int row=board.size() ;
    int col=board[0].size() ;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]==word[0]){
                bool ans=search(i,j,0,board,word) ;

                if(ans) return ans ;
            }
        }
    }
    return false ;
}


bool search(int row,int col,int indx,vector<vector<char>>& board,string word){
    
    if(indx==word.length())  return true  ;

    if(row<0 || col<0 || row>=board.size() || col>=board[0].size || board[row][col]!=word[0]){
        return false ;
    }

    board[row][col]="*" ;// mark current cell as visited

    int nRow[4]={-1,1,0,0} ;
    int nCol[4]={-1,1,0,0}  ;

    for(int i=0;i<4;i++){
        bool ans =search(row+nRow[i],col+nCol[i],indx+1,board,word) ;

        if(ans==true) return true  ;
    }
    board[row][col]=word[indx] ;
    return false ;
}


char nonRepChar(string word){
    int n=word.length() ;

    for(int i=0;i<n;i++){
       bool found=false ;
       for(int j=0;j<n;j++){
        if(i!=j && word[i]==word[j]){
            found=true ;
        }
       }
       if(!found) return word[i];
    }
    return "" ; 
}


char noReapeChar(string word){
    int n=word.length() ;
    vector<int> freqArr(26,0) ;

    for(char ch:word){
        freqArr[ch-'a']++ ;
    }
    //find first char with freq=1;
    for(char ch:word){
        if(freqArr[ch-'a']==1){
            return ch ;
        }
    }
    return "*" ;
}


bool isFreqSame(int freq1[],int fre2[]){
    for(int i=0;i<26;i++){
        if(freq1[i]==freq2[i]) return true ;
    }
    return false ;
}

bool permuInString(string s1,string s2){
    int freq[26]={0} ;

    for(int i=0;i<s1.length();i++){
        int indx=s1[i]-'a' ;
        freq[indx]++ ;
    }

    int windSize=s1.length() ;

    for(int i=0;i<s2.length();i++){
        int windIndx=0;
        int indx=i;

        int windFreq[26]={0} ;

        while(windIndx<windSize && indx<s2.length()){
            windFreq[s2[indx]='a']++ ;
            windIndx++ ;
            indx++ ;
        }
    if(isFreqSame(freq,windFreq)) return true 
        
    }
}



#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int count = 0;
    
    for (int a = 0; a * a <= n; ++a) {
        int b = n - a * a;
        if (b >= 0 && a + b * b == m) {
            count++;
        }
    }
    
    cout << count << endl;
    return 0;
}


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to check if a string is palindrome
bool isPalindrome(const string& s) {
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        ++l;
        --r;
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    
    string best = "";
    int n = s.length();
    
    // Generate all subsequences using bitmask
    for (int mask = 1; mask < (1 << n); ++mask) {
        string sub = "";
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sub += s[i];
            }
        }
        if (isPalindrome(sub)) {
            best = max(best, sub); // update if this palindrome is lex greater
        }
    }
    
    cout << best << endl;
    return 0;
}


