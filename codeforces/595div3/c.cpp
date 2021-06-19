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

vector<ll> vt;

void init() {
    vt.clear();
    vt.push_back(1);
    ll temp = 1;
    while(temp * 3 <= 1e18) {
        temp = temp * 3;
        vt.push_back(temp);
    }
    temp = temp * 3;
    vt.push_back(temp);
}

ll my_find(ll n) {
    int l = 0, r = vt.size();
    while(l < r - 1) {
        int mid = (l + r) / 2;
        if(vt[mid] <= n)
            l = mid;
        else
            r = mid;
    }
    return l;
}

ll dfs(ll n) {
    if(n == 0) return 0;
    ll m = my_find(n);
    ll up = (vt[m+1] - 1) / 2;
    if(n > up)
        return vt[m+1];
    if(n == up)
        return up;
    return vt[m] + dfs(n - vt[m]);
}

int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    #endif
    init();
    int q; scanf("%d", &q);
    while(q--) {
        ll n; scanf("%I64d", &n);
        ll ans = dfs(n);
        printf("%I64d\n", ans);
    }

    return 0;
}
