
int dp[100][100];

int solve(string a, int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    if (l >= r)
        return dp[l][r] = 0;
    dp[l][r] = min(solve(a, l + 1, r), solve(a, l, r - 1)) + 1;
    if (a[l] == a[r])
        dp[l][r] = min(dp[l][r], solve(a, l + 1, r - 1));
    return dp[l][r];
}