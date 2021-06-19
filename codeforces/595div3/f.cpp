#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<utility>
#include<sstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 210;
#define pr(x) cout << #x <<" = " << x << " ";
#define prln(x) cout << #x <<" = " << x << " " << endl;

int n, k;
int a[maxn], dp[maxn][maxn];
vector<int> vt[maxn];

void dfs(int u, int f) {
    for(auto v: vt[u]) {
        if(v == f) continue;
        dfs(v, u);
    }
    for(int dep = 0; dep < maxn; dep++) {
        if(dep == 0) {
            dp[u][dep] = a[u];
            for(auto v: vt[u]) {
                if(v == f) continue;
                dp[u][dep] += dp[v][k];
            }
        }
        else {
            dp[u][dep] = 0;
            for(auto v: vt[u]) {
                if(v == f) continue;
                int cur = dp[v][dep-1];
                for(auto other: vt[u]) {
                    if(other == f || other == v) continue;
                    cur += dp[other][max(k-dep, dep-1)];
                }
                dp[u][dep] = max(dp[u][dep], cur);
            }
        }
    }
    for(int i = maxn-2; i >= 0; i--)
        dp[u][i] = max(dp[u][i], dp[u][i+1]);
}

int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < n-1; i++) {
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        vt[u].push_back(v);
        vt[v].push_back(u);
    }
    dfs(0, -1);
    printf("%d\n", dp[0][0]);

    return 0;
}
