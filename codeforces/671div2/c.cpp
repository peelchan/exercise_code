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

int a[10005];

int main()
{
    #ifdef LOCAL
    //freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, x;
        scanf("%d%d", &n, &x);
        int hasc = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if(a[i] == x) hasc++;
            sum += a[i];
        }
        if(hasc == n)
            printf("0\n");
        else if(hasc || sum == n*x)
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}
