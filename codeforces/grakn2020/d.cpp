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
const ll inf = 1e18;
const int maxn = 1000100;
#define pr(x) cout << #x <<" = " << x << " ";
#define prln(x) cout << #x <<" = " << x << " " << endl;

int a[maxn], b[maxn], c[maxn], d[maxn];

int main()
{
    int n, m; scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &a[i], &b[i]);
    for(int i = 0; i < m; i++)
        scanf("%d %d", &c[i], &d[i]);
    vector<P> vt;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i] > c[j] || b[i] > d[j]) continue;
            vt.push_back(P(c[j]-a[i]+1, d[j]-b[i]+1));
        }
    }
    sort(vt.begin(), vt.end());
    for(int i = vt.size()-2; i >= 0; i--) {
        vt[i].second = max(vt[i].second, vt[i+1].second);
    }
    if(vt.size() == 0) {
        printf("0\n");
        return 0;
    }
    int ans = vt[0].second;
    for(int i = 0; i < vt.size()-1; i++)
        ans = min(ans, vt[i].first+vt[i+1].second);
    ans = min(ans, vt.back().first);
    printf("%d\n", ans);
    return 0;
}
