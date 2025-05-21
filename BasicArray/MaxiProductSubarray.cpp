//Maximum Product Subarray
// Given an integer array nums, find a subarray that has the largest product, and return the product.
// Example 1:
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

#include<iostream>
#include<vector>
using namespace std ;

int maxiProductSubarray(vector<int>& nums){
   int prefix=1;
   int suffix=1;
   int ans=nums[0];
   int n=nums.size() ;

   for(int i=0;i<n;i++){
    if(prefix==0) prefix=1;    // if anytime your encounter zero so product becomes zero so reset to 1
    if(suffix==0) suffix=1;

    prefix=prefix*nums[i];
    suffix=suffix*nums[n-i-1] ;

    ans=max(ans,max(prefix,suffix)) ; 
   }

   return ans ; 
}





// Intuition
// To solve the Maximum Product Subarray problem, we must account for how multiplication behaves differently compared to addition. While Kadane's algorithm handles addition with negative numbers well, multiplication becomes tricky due to the impact of:

// Negative numbers (which can flip signs)
// Zeros (which reset the product)
// So instead of Kadane’s algorithm, we use the insight that a subarray's product is maximized either by its entire segment, prefix, or suffix, especially when it contains negative numbers or zeros.

// Observations
// Only positive numbers:
// The maximum product is simply the product of the entire array.

// Even number of negative numbers:
// The product will be positive, so again the answer is the product of the entire array.

// Odd number of negative numbers:
// Multiplying all elements yields a negative product. To make it positive, we must exclude exactly one negative number, either from the start or the end, and choose the subarray (prefix/suffix) with the maximum product.

// Presence of zeros:
// A zero breaks the product into parts, resetting it to zero. So we split the array at zeros, and for each resulting subarray (non-zero), apply the logic in observation 3. The final answer is the maximum product among all these subarrays.

// Approach
// We simulate the logic above without explicitly splitting the array. We perform two traversals:

// From left to right (prefix)
// From right to left (suffix)
// We keep a running product in both directions and reset the product to 1 whenever a zero is encountered. At each step, we update the result as the maximum of current result, prefix product, and suffix product.

// Example
// Consider the array:
// [3, 2, -1, 4, -6, 3, -2, 6]

// This array has 3 negative numbers (odd count).
// Removing each negative splits the array into:

// After removing -1 → [3,2] and[4, -6, 3, -2, 6]
// After removing -6 → [3, 2, -1, 4] and [3,-2,6]
// After removing -2 → [3, 2, -1, 4, -6, 3]and [6]
// From each split, we check prefix and suffix products. The best result is the maximum of all these.

// Now with zeros:
// [-2, 3, 4, -1, 0, -2, 3, 1, 4, 0, 4, 6, -1, 4]

// Split it into:

// [-2, 3, 4, -1]
// [-2, 3, 1, 4]
// [4, 6, -1, 4]
// Apply the same logic to each subarray and return the maximum result among them.