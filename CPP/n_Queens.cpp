// PROBLEM
// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// SOLUTION
class Solution
{
public:
    vector<vector<string>> ans;
    void func(int n, int pos, vector<bool> &d1, vector<bool> &d2, vector<bool> &col, vector<string> &dp)
    {
        if (pos == n)
        {
            ans.push_back(dp);
            return;
        }
        for (int i = 0; i < n; i++)
            if (!col[i] && !d2[pos - i + n - 1] && !d1[pos + i])
            {
                col[i] = d2[pos - i + n - 1] = d1[pos + i] = true;
                dp[pos][i] = 'Q';
                func(n, pos + 1, d1, d2, col, dp);
                dp[pos][i] = '.';
                col[i] = d2[pos - i + n - 1] = d1[pos + i] = false;
            }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> dp(n, string(n, '.'));
        vector<bool> d1(2 * n - 1, false);
        vector<bool> d2(2 * n - 1, false);
        vector<bool> col(n, false);
        func(n, 0, d1, d2, col, dp);
        return ans;
    }
};