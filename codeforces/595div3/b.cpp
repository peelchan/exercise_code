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
const int maxn = 400010;
#define pr(x) cout << #x <<" = " << x << " ";
#define prln(x) cout << #x <<" = " << x << " " << endl;

int a[maxn], rans[maxn];
bool vis[maxn];

int dfs(int u, int ans) {
    int v = a[u] - 1;
    if(vis[v] == true) {
        rans[u] = ans;
        return ans;
    }
    ans += 1;
    vis[v] = true;
    ans = dfs(v, ans);
    rans[u] = ans;
    return ans;
}

int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif
    int q; scanf("%d", &q);
    while(q--) {
        int n; scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            vis[i] = true;
            dfs(i, 1);
        }
        for(int i = 0; i < n; i++)
            printf("%d ", rans[i]);
        printf("\n");
    }
    return 0;
}
