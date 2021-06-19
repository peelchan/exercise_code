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

int b[1005], in[1005], ans[1005];

bool conn[1005][1005], vis[1005];

int my_find() {
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        if(in[i] == 0)
            return i;
    }
    return -1;
}


int main()
{
    scanf("%d %d", &n, &m);
    memset(conn, 0, sizeof(conn));
    memset(in, 0, sizeof(in));
    for(int epoch = 0; epoch < m; epoch++) {
        memset(vis, 0, sizeof(vis));
        int s;
        scanf("%d", &s);
        for(int i = 0; i < s; i++) {
            scanf("%d", &b[i]);
            vis[b[i]] = true;
        }
        int st = b[0];
        int ed = b[s-1];
        for(int i = st; i <= ed; i++) {
            if(vis[i] == false) {
                for(int j = 0; j < s; j++)
                    conn[i][b[j]] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(conn[i][j]) {
                in[j]++;
            }
        }
    }

    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++)
        ans[i] = 1;
    while(1) {
        int id = my_find();
        if(id == -1) break;
        for(int i = 1; i <= n; i++) {
            if(conn[id][i]) {
                in[i]--;
                ans[i] = max(ans[i], ans[id] + 1);
            }
        }
        vis[id] = true;
    }

    int rans = 1;
    for(int i = 1; i <= n; i++)
        rans = max(rans, ans[i]);

    printf("%d\n", rans);
    return 0;
}
