// Problem: Maximum Sum Subarray of Size at Most K with No Adjacent Equal Elements
// 🔍 Problem Statement:
// You are given an array of integers arr of size n, and an integer k. Your task is to find the maximum possible sum of any subarray (contiguous elements) that satisfies both of the following constraints:

// The subarray contains at most k elements.

// No two adjacent elements in the subarray are equal.

// You need to find the maximum sum among all valid subarrays of size at most k where adjacent duplicates are not allowed.

// 📥 Input:
// An integer n — the number of elements in the array. (1 ≤ n ≤ 10⁵)

// An integer k — the maximum allowed subarray size. (1 ≤ k ≤ n)

// An array of n integers arr where -10⁴ ≤ arr[i] ≤ 10⁴.

// 📤 Output:
// A single integer — the maximum sum of any valid subarray that satisfies the above conditions. give me code for this and give me corrected c++ code plz . forst give me brute force apporach then best optimal apporach . 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSumBruteForce(vector<int>& arr, int k) {
    int n = arr.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        bool isValid = true;
        for (int j = i; j < n && j - i + 1 <= k; ++j) {
            if (j > i && arr[j] == arr[j - 1]) {
                isValid = false;
                break;
            }
            sum += arr[j];
            if (isValid) {
                maxSum = max(maxSum, sum);
            }
        }
    }

    return maxSum;
}

int maxSumOptimal(vector<int>& arr, int k) {
    int n = arr.size();
    int maxSum = INT_MIN;
    int windowStart = 0;
    int currSum = arr[0];

    for (int windowEnd = 1; windowEnd < n; ++windowEnd) {
        if (arr[windowEnd] == arr[windowEnd - 1]) {
            currSum = arr[windowEnd];
            windowStart = windowEnd;
        } else {
            currSum += arr[windowEnd];
            while (windowEnd - windowStart + 1 > k) {
                currSum -= arr[windowStart];
                windowStart++;
            }
        }
        maxSum = max(maxSum, currSum);
    }

    for (int i = 0; i < n; ++i) {
        maxSum = max(maxSum, arr[i]);
    }

    return maxSum;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the maximum subarray size (k): ";
    cin >> k;

    vector<int> arr(n);
    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Brute Force: " << maxSumBruteForce(arr, k) << endl;
    cout << "Optimal: " << maxSumOptimal(arr, k) << endl;

    return 0;
}

// Enter the size of the array: 6
// Enter the maximum subarray size (k): 3
// Enter the array elements:
// 1 2 2 3 4 5


