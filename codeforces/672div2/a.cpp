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

bool myReverse(int n) {
    for(int i = 0; i < n-1; i++) {
        if(a[i] > a[i+1]) continue;
        return false;
    }
    return true;
}

bool myUnique(int n) {
    sort(a, a+n);
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) return false;
    }
    return true;
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
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        if(myReverse(n) && myUnique(n))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
