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

int a[maxn];

int main()
{
    int t; scanf("%d", &t);
    while(t--) {
        int n, k; scanf("%d %d", &n, &k);
        int cnt = 1;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            // cout << a[i] << " " << a[i-1] << endl;
            if(i && (a[i] != a[i-1])) cnt++;
        }
        // prln(cnt);
        if(k == 1) {
            if(cnt == 1)
                printf("1\n");
            else
                printf("-1\n");
        } else {
            if(cnt == 1)
                printf("1\n");
            else
                printf("%d\n", 1+(cnt-2)/(k-1));
        }
    }
    return 0;
}
