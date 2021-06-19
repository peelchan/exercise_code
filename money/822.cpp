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

int all_num;

struct Node {
    int w, l, r;
    int son_num;
    int son_dis;
    int up_dis;
    int ans;
}node[maxn];


void dfs1(int u) {
    int lson = node[u].l;
    int rson = node[u].r;
    if(lson) {
        dfs1(lson);
    }
    if(rson) {
        dfs1(rson);
    }
    node[u].son_num = node[u].w + node[lson].son_num + node[rson].son_num;
    node[u].son_dis = node[lson].son_dis + node[rson].son_dis + node[lson].son_num + node[rson].son_num;
}

void dfs2(int u, int f) {
    int lson = node[u].l;
    int rson = node[u].r;
    if(f == -1)
        node[u].up_dis = 0;
    else
        node[u].up_dis = node[f].up_dis + node[f].son_dis - node[u].son_dis - node[u].son_num + all_num - node[u].son_num;

    if(lson) {
        dfs2(lson, u);
    }
    if(rson) {
        dfs2(rson, u);
    }
}

int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif

    int n;
    scanf("%d", &n);
    all_num = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d %d %d", &node[i].w, &node[i].l, &node[i].r);
        all_num += node[i].w;
    }
    node[0].w = node[0].l = node[0].r = node[0].son_num = node[0].son_dis = 0;

    dfs1(1);
    dfs2(1, -1);

    int ans = node[1].son_dis;
    for(int i = 1; i <= n; i++) {
        ans = min(ans, node[i].up_dis + node[i].son_dis);
    }
    printf("%d\n", ans);
    return 0;
}
