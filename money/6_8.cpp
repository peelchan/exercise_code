int dp[50][100];
int x[100], prefix[100], suffix[100];
#define inf 1e9 + 7;

int min(int a, int b)
{
    return 0;
}

int main()
{
    int n = 100;
    int k = 50;

    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = i * x[i] - prefix[i];
    }

    for (int kk = 2; kk <= k; kk++)
    {
        for (int j = kk; j <= n; j++)
        {
            dp[kk][j] = inf;
            int mid = j;
            for (int i = j - 1; i >= kk - 1; i--)
            {
                while (x[mid] - x[i] > x[j] - x[mid])
                    mid--;
                int extra_v = prefix[mid] - prefix[i - 1] - (mid - i + 1) * x[i] + (j - mid) * x[j] - (prefix[j] - prefix[mid]);
                dp[kk][j] = min(dp[kk][j], dp[kk - 1][i] + extra_v);
            }
        }
    }

    int ans = inf;
    for (int i = k; i <= n; i++)
    {
        int tans = dp[k][i] + suffix[i + 1] - (n - 1 - i) * x[i];
        ans = min(ans, tans);
    }

    return 0;
}
