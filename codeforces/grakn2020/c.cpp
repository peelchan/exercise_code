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
double b[maxn], c[maxn];

int solve(int x) {
    int l = 0, r = x+1;
    while(l < r-1) {
        int mid = (l+r)/2;
        if(b[mid] <= c[mid])
            l = mid;
        else
            r = mid;
    }
    return l;
}

int main()
{
    int t; scanf("%d", &t);
    while(t--) {
        int n, l; scanf("%d %d", &n, &l);
        a[0] = 0; a[n+1] = l;
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for(int i = 0; i <= n+1; i++) {
            if(i == 0)
                b[i] = 0;
            else
                b[i] = b[i-1] + 1.0*(a[i]-a[i-1])/i;
        }
        for(int i = n+1; i >= 0; i--) {
            if(i == n+1)
                c[i] = 0;
            else
                c[i] = c[i+1] + 1.0*(a[i+1]-a[i])/(n+1-i);
        }
        int last = solve(n+1);
        double have_run;
        if(b[last] >= c[last+1]) {
            have_run = (b[last]-c[last+1])*(n+1-last);
        } else {
            have_run = (c[last+1]-b[last])*(last+1);
        }
        // cout << last << " " << have_run << endl;
        printf("%f\n", max(b[last], c[last+1])+(a[last+1]-a[last]-have_run)/(n+2));
    }
    return 0;
}
