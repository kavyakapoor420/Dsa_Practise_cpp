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








#include<iostream>
#include<vector>
using namespace std ;

void solve(int index, int arr[], int n, vector<int> &ds, vector<vector<int>> &ans) {
    if (index == n) {
        ans.push_back(ds);
        return;
    }
    // Exclude the current element
    solve(index + 1, arr, n, ds, ans);
    
    // Include the current element
    ds.push_back(arr[index]);
    solve(index + 1, arr, n, ds, ans);
    
    // Backtrack
    ds.pop_back();
}
vector<vector<int>> subsets(int arr[], int n) {
    vector<vector<int>> ans;
    vector<int> ds;
    solve(0, arr, n, ds, ans);
    return ans;
}
int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> result = subsets(arr, n);
    
    cout << "Subsets are: " << endl;
    for (const auto &subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        int changes = 0;

        // Check last row (all columns except last one)
        for (int j = 0; j < m - 1; ++j) {
            if (grid[n - 1][j] != 'R') {
                changes++;
            }
        }

        // Check last column (all rows except last one)
        for (int i = 0; i < n - 1; ++i) {
            if (grid[i][m - 1] != 'D') {
                changes++;
            }
        }

        cout << changes << endl;
    }

    return 0;
}




int n;
cin>>n;

int matrix[101][101];
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>matrix[i][j];
    }
}

int mid=n/2;
int sum=0;
int used[101][101]={false};
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i==j || i+j==n-1 || i==mid || j==mid){
            sum+=matrix[i][j];
            used[i][j]=true ;
        }
    }
}
return sum ;

void makeRowZero(vector<int>& row,int colSize){
    for(int i=0;i<colSize;i++){
        row[i]=0;
    }
}

void makeColZero(vector<vector<int>>& matrix,int colIndx,int rowSize){
    for(int i=0;i<rowSize;i++){
        matrix[i][colIndx]=0;
    }
}

void setMatrixZero(vector<vector<int>>& matrix){
    int n=matrix.size() ;
    int m=matrix[0].size() ;
    vector<pair<int,int>> zerosPos;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                zerosPos.push_back({i,j})
            }
        }
    }
    for(auto pos:zerosPos){
        makeRowZero(matrix[pos.first],m) ;
        makeColZero(matrix,n,pos.second) ;
    }
}

bool search(vector<vector<char>>& board,string word,int row,int col,int indx){
    if(indx==word.length()) return true;
    //check boundary conditions
    if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || board[row][col]!=word[indx]){
        return false ;
    }
    //mark current cell as visited;
    board[row][col]="*" ;
    int nRow[4]={-1,-1,0,0} ;
    int nCol[4]={-1,1,0,0} ;
    for(int i=0;i<4;i++){
        bool ans=search(board,word,row+nRow[i],col+nCol[i],indx+1) ;
        if(ans==true){
            return true ; 
        }
    }
    //backtrack restore the original character in board 
    board[row][col]=word[indx] ;
    return false ;
}

bool exist(vector<vector<char>>& board,string word){
    int n=board.size();
    int m=board[0].size() ;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0]){
                bool ans=solve(board,word,i,j,0) ;
                if(ans==true){
                    return true ;
                }
            }
        }
    }
    return false
}

int longSubarraySumK(vector<int>& arr ,int k){
    int len=arr.size() ;
    int maxLen=0
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(sum<k){
                maxLen=max(maxLen,j-i+1) ;
            }else if(sum>k){
                break ;
            }
        }
    }
    return maxLen ;
}

//sliding window approach 
int maxSubarraySumK(vector<int>& arr, int k){
    int n=arr.size() ;
    int maxLen =0;
    int l=0,r=0,sum=0;
    while(r<n){
        sum=sum+arr[r];
        while(sum>k){
            sum=sum-arr[l];
            l++;
        }
        if(sum<k){
            maxLen=max(maxLen,r-l+1) ;
        }
        r=r+1; 
    }
    return maxLen ; 
}

vector<int> productOfArray(vector<int>& nums){
    int n=nums.size() ;
    vector<int> ans ;
    for(int i=0;i<n;i++){
        int prod=1;
        for(int j=0;j<n;j++){
            if(i!=j){
                prod=prdo*nums[j] ;
            }
        }
        ans.push_back(prod) ;
    }
    return ans ; 
}

vector<int> productOfArray(vector<int>& nums){
    int n=nums.size() ;
    vector<int> ans(n) ;
    vector<int> prefix(n) ;
    vector<int> suffix(n) ;

    preifx[0]=nums[0];
    for(int i=1;i<n;i++){
       prefix[i]=prefix[i]*nums[i];
    }
    suffix[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i]*nums[n-i-1] ;
    }
    for(int i=0;i<n;i++){
       int res=prefix[i]*suffix[i];
       ans.push_back(res) ;
    }
    return ans ; 
}

int longestSubstring(string str){
    int n=str.length() ;
    int maxLen=0;
    int freq[256]={0};
    int l=0,r=0;
    while(r<n){
        freq[str[r]]++;
        while(freq[str[r]]>1){
            freq[str[r]]-;
            l++;
        }
        maxLen=max(maxLen,r-l+1) ;
        r++ ;
    }
    return maxLen ;  
}

int longestSubstring(string str){
    int n=str.length() ;
    unordered_set<char> st;
    int maxLen=0;
    int l=0,r=0;
    while(r<n){
        if(set.count(str[r]==0)){
            st.insert(str[r])
            maxLen=max(maxLen,r-l+1) ;
        }else{
            while(set.count(str[r])){
                set.erase(str[l]) ;
                l++;
            }
            set.insert(str[r]) ;
        }
        r++ ;
    }
    return maxLen ;
}