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

int main()
{
    #ifdef LOCAL
    //freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        string s;
        cin >> s;
        int fg = n % 2;
        int oo = 0, oe = 0, eo = 0, ee = 0;
        for(int i = 0; i < n; i++) {
            int dig = s[i] - '0';
            if(i%2 == 0) {
                if(dig%2 == 0)
                    oe = 1;
                else
                    oo = 1;
            } else {
                if(dig%2 == 0)
                    ee = 1;
                else
                    eo = 1;
            }
        }
        if(fg) {
            if(oo)
                printf("1\n");
            else
                printf("2\n");
        } else {
            if(ee)
                printf("2\n");
            else
                printf("1\n");
        }
    }
    return 0;
}
