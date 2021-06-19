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

int a[maxn];

int main()
{
    #ifdef LOCAL
    freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif
    int q; scanf("%d", &q);
    while(q--) {
        int n; scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a+n);
        bool ok = false;
        for(int i = 1; i < n; i++)
            if(a[i] == a[i-1] + 1) ok = true;
        if(ok)
            printf("2\n");
        else
            printf("1\n");
    }
    return 0;
}
