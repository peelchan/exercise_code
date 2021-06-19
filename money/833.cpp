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

int n, m;

bool vis[maxn];
int t[maxn], ans[maxn], f[maxn];

struct Node {
    int x, y, v;
    Node(int xx=0, int yy=0, int vv=0):x(xx),y(yy),v(vv) {}

    bool operator<(const Node& a) {
        return v > a.v;
    }
}node[maxn];

void init(int num) {
    for(int i = 0; i < num; i++) f[i] = i;
}

int get_f(int x) {
    if(f[x] == x)
        return x;
    f[x] = get_f(f[x]);
    return f[x];
}

bool merge(int x, int y){
    int fx = get_f(x);
    int fy = get_f(y);
    if(fx == fy)
        return true;
    f[fx] = fy;
    return false;
}

int get_id(int x, int y) {
    if(x >= n || x < 0) return -1;
    if(y >= m || y < 0) return -1;
    return x*m + y;
}

int main()
{
    scanf("%d %d", &n, &m);
    init(n*m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x; scanf("%d", &x);
            int id = get_id(i, j);
            node[id] = Node(i, j, x);
        }
    }
    sort(node, node + n*m);
    memset(vis, false, sizeof(vis));

    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        scanf("%d", &t[i]);
    }

    int clu = 0;
    int left_node = 0;
    for(int epoch = T-1; epoch >= 0; epoch--) {
        int water = t[epoch];
        while(left_node < n*m && node[left_node].v > water) {
            clu++;
            Node tmp = node[left_node];
            int cid = get_id(tmp.x, tmp.y);
            for(int i = -1; i <= 1; i++) {
                for(int j = -1; j <= 1; j++) {
                    if(abs(i) + abs(j) != 1) continue;
                    int id = get_id(tmp.x+i, tmp.y+j);
                    if(id == -1) continue;
                    if(!vis[id]) continue;
                    bool isSame = merge(cid, id);
                    if(!isSame) clu--;
                }
            }
            vis[cid] = true;
            left_node++;
        }
        ans[epoch] = clu;
    }

    for(int i = 0; i < T; i++)
        printf("%d ", ans[i]);

    return 0;
}

