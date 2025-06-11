#include<iostream>
#include<vector>
using namespace std ;

void sortArrayof012(vector<int>& nums){
    int zeroCnt=0;
    int oneCnt=0;
    int twoCnt=0;

    for(int i=0;i<nums.size();i++){
        if(nums[i]==0) zeroCnt++;
        else if(nums[i]==1) oneCnt++ ;
        else  twoCnt++;
    }

    int i=0;
    while(zeroCnt--){
        nums[i++]=0 ;
    }
    while(oneCnt--){
        nums[i++]=1;
    }
    while(twoCnt--){
        nums[i++]=2 ;
    }
}

//bubble sort algo -> brute force approach 
void sortArrayof012(vector<int>& nums){
    int n=nums.size() ;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]) ;
            }
        }
    }
}




#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    int limit = sqrt(num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Main function to solve the problem
int sumOfThreeLargestPrimes(string s) {
    unordered_set<int> uniquePrimes;

    int n = s.length();

    // Generate all substrings
    for (int i = 0; i < n; ++i) {
        string numStr = "";
        for (int j = i; j < n; ++j) {
            numStr += s[j];

            // Remove leading zeros by converting to int
            int num = stoi(numStr);

            // Check if prime and insert into set
            if (isPrime(num)) {
                uniquePrimes.insert(num);
            }
        }
    }

    // Convert set to vector and sort in descending order
    vector<int> primes(uniquePrimes.begin(), uniquePrimes.end());
    sort(primes.rbegin(), primes.rend()); // sort in descending

    // Sum up to 3 largest primes
    int sum = 0;
    for (int i = 0; i < min(3, (int)primes.size()); ++i) {
        sum += primes[i];
    }

    return sum;
}

// Example usage
int main() {
    string s1 = "12234";
    cout << "Input: " << s1 << " → Output: " << sumOfThreeLargestPrimes(s1) << endl;

    string s2 = "111";
    cout << "Input: " << s2 << " → Output: " << sumOfThreeLargestPrimes(s2) << endl;

    return 0;
}



#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to check if a number is prime (optimized)
bool isPrime(long long num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (long long i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Updated function with long long return type
long long sumOfLargestPrimes(string s) {
    unordered_set<long long> uniquePrimes;
    int n = s.length();

    // Generate all substrings
    for (int i = 0; i < n; ++i) {
        string numStr = "";
        for (int j = i; j < n; ++j) {
            numStr += s[j];

            // Convert substring to number using stoll (string to long long)
            long long num = stoll(numStr);

            if (isPrime(num)) {
                uniquePrimes.insert(num);
            }
        }
    }

    // Sort unique primes in descending order
    vector<long long> primes(uniquePrimes.begin(), uniquePrimes.end());
    sort(primes.rbegin(), primes.rend());

    // Compute sum of top 3 largest primes
    long long sum = 0;
    for (int i = 0; i < min(3, (int)primes.size()); ++i) {
        sum += primes[i];
    }

    return sum;
}





class Solution {
    public:
        
        bool isPrime(int n){
            if(n<2) return false ;
            if(n==2) return true ;
            if(n%2==0) return false ;
            
            for(int i=3;i*i<=n;i++){
                if(n%i==0){
                    return false ;
                }
            }
            return true ;
        }
        
        
        long long sumOfLargestPrimes(string s) {
            unordered_set<long long> st ;
            int n=s.length() ;
            long long ans=0;
            //generate all possible substring first 
            for(int i=0;i<n;i++){
                string sub="";
                for(int j=i;j<n;j++){
                    sub+=s[j];
                    //convert this substring into integer
                    int number=stoi(sub) ;
                    
                    if(isPrime(number)){
                        st.insert(number) ;
                    }
                }
            }
            
            vector<long long> primeNumbers(st.begin(),st.end()) ;
            
            sort(primeNumbers.rbegin(),primeNumbers.rend()) ;
            
            for(int i=0;i<min(3,(int)primeNumbers.size());i++){
                  ans+=primeNumbers[i];
            }
            return ans ;
        }
    };


    #include <bits/stdc++.h>
    using namespace std;
    
    class Solution {
    public:
        int maxNonOverlappingSubstrings(string word) {
            int n = word.length();
            vector<pair<int, int>> validSubstrings;
    
            // Step 1: Generate all substrings of length >= 4 that start and end with the same character
            for (int i = 0; i < n; ++i) {
                for (int j = i + 3; j < n; ++j) {
                    if (word[i] == word[j]) {
                        validSubstrings.push_back({i, j});
                    }
                }
            }
    
            // Step 2: Sort substrings by their end index (greedy choice)
            sort(validSubstrings.begin(), validSubstrings.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second;
            });
    
            // Step 3: Greedily pick non-overlapping intervals
            int count = 0;
            int lastEnd = -1;
            for (const auto& [start, end] : validSubstrings) {
                if (start > lastEnd) {
                    count++;
                    lastEnd = end;
                }
            }
    
            return count;
        }
    };
    
    // Example usage:
    int main() {
        Solution sol;
        cout << sol.maxNonOverlappingSubstrings("abcdeafdef") << endl; // Output: 2
        cout << sol.maxNonOverlappingSubstrings("bcdaaaab") << endl;   // Output: 1
        return 0;
    }
    
    #include <iostream>
    #include <vector>
    using namespace std;
    
    int main() {
        int t;
        cin >> t;
        while (t--) {
            int n;
            cin >> n;
    
            vector<int> a(n);
            int even = 0, odd = 0;
    
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
                if (a[i] % 2 == 0)
                    even++;
                else
                    odd++;
            }
    
            // To make min and max same parity, remove the fewer type (odd or even)
            cout << min(even, odd) << endl;
        }
    
        return 0;
    }


    #include<iostream>
    #include<vector>
    using namespace std;
     
        bool isFashionable(const vector<int>& arr) {
            if (arr.empty()) return false;
            int minVal = *min_element(arr.begin(), arr.end());
            int maxVal = *max_element(arr.begin(), arr.end());
            return (minVal + maxVal) % 2 == 0;
        }
        
        int main(vector<int>& a) {
            int n = a.size();
            int maxFashionableSize = 0;
            
            // Try all possible subsets using bit manipulation
            for (int mask = 1; mask < (1 << n); mask++) {
                vector<int> subset;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        subset.push_back(a[i]);
                    }
                }
                
                if (isFashionable(subset)) {
                    maxFashionableSize = max(maxFashionableSize, (int)subset.size());
                }
            }
            
            return n - maxFashionableSize;
        }
    
    