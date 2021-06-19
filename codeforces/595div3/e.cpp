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

int a[maxn], b[maxn], dp[maxn][2];

int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif
    int n, c; scanf("%d%d", &n, &c);
    for(int i = 0 ; i < n-1; i++) scanf("%d", &a[i]);
    for(int i = 0 ; i < n-1; i++) scanf("%d", &b[i]);
    dp[0][0] = 0; dp[0][1] = c;
    for(int i = 1; i < n; i++) {
        dp[i][0] = min(dp[i-1][0]+a[i-1], dp[i-1][1]+a[i-1]);
        dp[i][1] = min(dp[i-1][0]+b[i-1]+c, dp[i-1][1]+b[i-1]);
    }
    for(int i = 0; i < n; i++) {
        printf("%d ", min(dp[i][0], dp[i][1]));
    }
    return 0;
}
