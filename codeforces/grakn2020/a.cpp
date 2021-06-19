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

int a[maxn], b[maxn], c[maxn];

int main()
{
    int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &b[i]);
        for(int i = 0; i < n; i++)
            scanf("%d", &c[i]);
        int pre = -1;
        int st = a[0];
        for(int i = 0; i < n-1; i++) {
            int temp;
            if(a[i] != pre) {
                temp = a[i];
            } else {
                temp = b[i];
            }
            pre = temp;
            printf("%d ", temp);
        }
        int temp;
        if(a[n-1] != pre && a[n-1] != st)
            temp = a[n-1];
        else if(b[n-1] != pre && b[n-1] !=st)
            temp = b[n-1];
        else
            temp = c[n-1];
        printf("%d ", temp);
        printf("\n");
    }
    return 0;
}
