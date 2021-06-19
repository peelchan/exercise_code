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

int a[maxn], b[maxn];

int main()
{
    #ifdef LOCAL
    //freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n);
    memset(b, -1, sizeof(b));
    for(int i = 0; i < n/2; i++)
        b[i*2] = a[n-1-i];
    if(b[n-1] == -1)
        b[n-1] = a[n-1-n/2];
    for(int i = 0; i < (n-1)/2; i++)
        b[i*2+1] = a[(n-1)/2-1-i];
    int ans = 0;
    for(int i = 1; i < n-1; i++)
        if(b[i] < b[i-1] && b[i] < b[i+1])
            ans++;
    printf("%d\n", ans);
    for(int i = 0; i < n; i++)
        printf("%d ", b[i]);
    return 0;
}
