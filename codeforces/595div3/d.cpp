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

set<P> st;
vector<int> ans;

struct Node {
    int l, r, id;
}node[maxn];

bool cmp(Node& a, Node& b) {
    return a.l < b.l;
}

int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif
    int n, k; scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &node[i].l, &node[i].r);
        node[i].id = i + 1;
    }
    sort(node, node+n, cmp);
    for(int i = 0; i < n; i++) {
        int cur = node[i].l;
        while(st.size() && st.begin()->first < node[i].l)
            st.erase(st.begin());
        st.insert(P(node[i].r, node[i].id));
        while(st.size() > k) {
            ans.push_back((--st.end())->second);
            st.erase(--st.end());
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);

    return 0;
}
