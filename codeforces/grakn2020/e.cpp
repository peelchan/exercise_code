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
const int maxn = 400010;
#define pr(x) cout << #x <<" = " << x << " ";
#define prln(x) cout << #x <<" = " << x << " " << endl;

int a[maxn], b[maxn];

struct Edge {
    int u, v, val;
    Edge(int u, int v, int val):u(u), v(v), val(val) {}
    bool operator < (const Edge& rhs) {
        return val < rhs.val;
    }
};

vector<Edge> vt;

int main()
{
    int m, n; scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    for(int i = 0; i < m; i++) {
        int s; scanf("%d", &s);
        while(s--) {
            int x; scanf("%d", &x);
            x--;
            vt.push_back(Edge(i, m+x, a[i]+b[x]));
        }
    }
    sort(vt.begin(), vt.end());
    return 0;
}
