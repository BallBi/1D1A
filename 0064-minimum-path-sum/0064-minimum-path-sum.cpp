class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dp[201][201] = {0,};
        int m = grid.size();
        int n = grid[0].size();

        dp[0][0] = grid[0][0];

        for(int i = 1; i<n; ++i)
            dp[0][i] = dp[0][i-1] + grid[0][i]; 

        for(int i = 1 ; i<m; ++i)
        {
            dp[i][0] = dp[i-1][0] + grid[i][0];
            for(int j = 1; j<n; ++j)
            {
                dp[i][j] = dp[i-1][j]> dp[i][j-1] ? dp[i][j-1] + grid[i][j] : dp[i-1][j] + grid[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};