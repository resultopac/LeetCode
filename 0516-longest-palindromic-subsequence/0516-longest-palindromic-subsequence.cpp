#include <stack>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:


    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        stack<pair<int,int>> st;
        st.push({0,n-1});
        while (!st.empty()) {
            int i = st.top().first;
            int j = st.top().second;
            if (i > j) {
                dp[i][j] = 0;
                st.pop();
            }else if (i == j) {
                dp[i][j] = 1;
                st.pop();
            }else if (s.at(i) == s.at(j)) {
                if (dp[i+1][j-1] == -1) {
                    st.push({i+1,j-1});
                }else {
                    dp[i][j] = 2+dp[i+1][j-1];
                    st.pop();
                }
            }else {
                if (dp[i+1][j] == -1) {
                    st.push({i+1,j});
                    if (dp[i][j-1] == -1) {
                        st.push({i,j-1});
                    }
                }
                else if (dp[i][j-1] == -1) {
                    st.push({i,j-1});
                }else {
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                    st.pop();
                }
            }
        }

        return dp[0][s.size()-1];

    }

};
