#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size()+1 ; int n = grid.at(0).size()+1;
        vector<vector<int>> dp(m, vector<int>(n, 999999));
        dp[0][1] = 0;
        dp[1][0] = 0;

        for (int i = 1 ; i < m ; i++) {
            for (int j = 1; j < n ; j++) {
                dp[i][j] = grid[i-1][j-1] + min(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[m-1][n-1];

    }
};