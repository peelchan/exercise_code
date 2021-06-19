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

ll ans = 0;
int a[maxn];

void erase(int x) {
    if(a[x] > a[x-1] && a[x] > a[x+1]) ans -= a[x];
    if(a[x] < a[x-1] && a[x] < a[x+1]) ans += a[x];
}

void insert(int x) {
    if(a[x] > a[x-1] && a[x] > a[x+1]) ans += a[x];
    if(a[x] < a[x-1] && a[x] < a[x+1]) ans -= a[x];
}

int main()
{
    #ifdef LOCAL
    //freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif
    int t; scanf("%d", &t);
    while(t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        ans = 0;
        a[0] = a[n+1] = -1;
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 1; i <= n; i++) {
            if(a[i] > a[i-1] && a[i] > a[i+1]) ans += a[i];
            if(a[i] < a[i-1] && a[i] < a[i+1]) ans -= a[i];
        }
        printf("%I64d\n", ans);
        while(q--) {
            int l, r; scanf("%d %d", &l, &r);
            for(int i = -1; i <= 1; i++)
                erase(l+i);
            if(l+1 < r-1) erase(r-1);
            if(l+1 < r) erase(r);
            if(l != r) erase(r+1);
            swap(a[l], a[r]);
            for(int i = -1; i <= 1; i++)
                insert(l+i);
            if(l+1 < r-1) insert(r-1);
            if(l+1 < r) insert(r);
            if(l != r) insert(r+1);
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
