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

struct Node {
    int val;
    Node* l;
    Node* r;
};

int bit[50];
int bitCnt = 32;

Node* newNode(int val) {
    Node* node = new(Node);
    node->l = node->r = nullptr;
    node->val = val;
    return node;
}

ll query(Node* root, int level) {
    if(root == nullptr) return 0;
    if(level < 0) return 0;
    if(bit[level] == 0) {
        return query(root->l, level-1);
    }
    if(root->r == nullptr) return 0;
    return root->r->val;
}

void add(Node* root, int level) {
    if(level < 0) return;
    if(bit[level] == 0) {
        if(root->l == nullptr) {
            root->l = newNode(0);
        }
        root->l->val += 1;
        add(root->l, level-1);
    } else {
        if(root->r == nullptr) {
            root->r = newNode(0);
        }
        root->r->val += 1;
        add(root->r, level-1);
    }
}

int main()
{
    #ifdef LOCAL
    //freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        ll ans = 0;
        Node* root = newNode(0);
        for(int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            for(int j = 0; j < bitCnt; j++) bit[j] = (x >> j) & 1;
            ans += query(root, bitCnt-1);
            // cout << ans << endl;
            add(root, bitCnt-1);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
