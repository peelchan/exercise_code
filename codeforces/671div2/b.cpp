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

ll stair[100];

void init() {
    stair[0] = 1;
    for(int i = 1; i < 31; i++)
        stair[i] = 2*stair[i-1] + 1;
    for(int i = 0; i < 31; i++)
        stair[i] = (1+stair[i])*stair[i]/2;
    for(int i = 1; i < 31; i++)
        stair[i] += stair[i-1];
}

int solve(ll x) {
    int l = 0, r = 31;
    while(l < r-1) {
        int mid = (l+r)/2;
        if(stair[mid] <= x)
            l = mid;
        else
            r = mid;
        //cout << stair[mid] << " " << x << " " << l << " " << r << " " << mid << endl;
    }
    return l+1;
}

int main()
{
    #ifdef LOCAL
    //freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif

    init();
    int t;
    scanf("%d", &t);
    while(t--) {
        ll x;
        scanf("%I64d", &x);
        printf("%d\n", solve(x));
    }
    return 0;
}
