// 64. Minimum Path Sum

// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.




#include<iostream>
#include<vector>
using namespace std ;

int helper(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp){
    int n = grid.size();
      int m = grid[0].size();
      if (row >= n || col >= m || row < 0 || col < 0)
          return INT_MAX;
      if (dp[row][col] != -1) {
          return dp[row][col];
      }
      if (row == n - 1 && col == m - 1) {
          return dp[row][col] = grid[row][col]; //?
      }
      int right = helper(grid, row, col + 1, dp);
      int down = helper(grid, row + 1, col, dp);
      return dp[row][col] = grid[row][col] + min(right, down);

  }
  int minPathSum(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      vector<vector<int>> dp(n, vector<int>(m, -1));
      return helper(grid, 0, 0, dp);

  }

  Application for Summer Internship on AI-Based Urban Traffic Dataset – Kavya Kapoor

  Dear Professor [Last Name],

I hope this message finds you well.

My name is Kavya Kapoor, and I am currently pursuing B.Tech in Computer Science at Maharaja Agrasen Institute of Technology, Delhi. I recently came across the call for the summer internship program on Building AI Datasets for Indian Urban Traffic Challenges, and I felt strongly compelled to write to you directly.

I have a strong passion for AI and computer vision, especially in solving real-world challenges with social impact. In one of my recent projects (BetterWeb), I developed an AI-powered Chrome extension to support users with cognitive impairments using the Gemini API, which taught me the importance of precision, context-awareness, and user-centric design—qualities that directly apply to image annotation work.

This internship aligns perfectly with my interests and skill set. I am confident that my technical foundation, keen attention to detail, and eagerness to learn would allow me to contribute effectively to your research team. I am genuinely motivated by the prospect of working on a government-supported initiative at IISc and would be truly grateful for an opportunity to be mentored under your guidance.

I am also open to working in an unpaid capacity—I value the learning experience and mentorship more than anything.

Thank you for considering my request. I have attached my resume for your reference, and I’d be happy to share any additional details you may need.

Looking forward to hearing from you.

Warm regards,
Kavya Kapoor
B.Tech CSE, MAIT, Delhi
📧 [Your Email Address]
📞 [Your Phone Number]
🔗 [LinkedIn or Portfolio link, if you'd like to include]