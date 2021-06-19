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
const int maxn = 100010;
#define pr(x) cout << #x <<" = " << x << " ";
#define prln(x) cout << #x <<" = " << x << " " << endl;

int n;
bool vis[maxn];
vector<int> prime, nprime, times, vt;
map<int, int> mp;

void init(int n) {
    memset(vis, 0, sizeof(vis));
    for(int i = 2; i < n; i++) {
        if(!vis[i]) prime.push_back(i);
        for(int j = 0; j < prime.size(); j++) {
            if(i*prime[j] > n) break;
            vis[i*prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

void decomp(int n) {
    int cur = 0;
    while(n != 1 && cur != (prime.size()-1)) {
        if(n % prime[cur] == 0) {
            int cnt = 0;
            while(n % prime[cur] == 0) {
                n /= prime[cur];
                cnt++;
            }
            nprime.push_back(prime[cur]);
            times.push_back(cnt);
        }
        cur++;
    }
    if(n != 1) {
        nprime.push_back(n);
        times.push_back(1);
    }
}

int mypow(int x, int y) {
    if(y == 0) return 1;
    if(y == 1) return x;
    int ans = mypow(x, y/2);
    ans *= ans;
    if(y%2)
        ans = ans * x;
    return ans;
}

void dfs(int pmul, int lev) {
    if(lev == nprime.size()) {
        if(!mp[pmul] && pmul != n) {
            mp[pmul] = 1;
            vt.push_back(pmul);
        }
        return;
    }
    for(int i = 0; i <= times[lev]; i++) {
        dfs(pmul*mypow(nprime[lev], i), lev+1);
    }
}

void solve(int pre, int bac) {
    vt.clear();
    int oriPre = times[pre];
    int oriBac = times[bac];
    times[bac] = 0;
    times[pre] -= 1;
    dfs(nprime[pre], 0);

    times[pre] = oriPre-1;
    times[bac] = oriBac-1;
    dfs(nprime[bac]*nprime[pre], 0);
    times[pre] = oriPre;
    times[bac] = oriBac;
}

void mypr() {
    for(int i = 0; i < vt.size(); i++)
        printf("%d ", vt[i]);
}

int main()
{
    #ifdef LOCAL
    //freopen("in.txt","r",stdin);
    //freopen("data.out.txt","w",stdout);
    #endif
    init(100000);
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        nprime.clear();
        times.clear();
        mp.clear();
        decomp(n);
        for(int i = 0; i < nprime.size(); i++) {
            if(i) {
                solve(i-1, i);
                mypr();
            }
            printf("%d ", nprime[i]);
            mp[nprime[i]] = 1;
            if(nprime.size() > 1 && i == nprime.size()-1) {
                solve(i, 0);
                mypr();
            }
        }
        if(nprime.size() == 1) {
            for(int i = 2; i < times[0]; i++) {
                printf("%d ", mypow(nprime[0], i));
            }
        }
        if(nprime.size() != 1 || nprime[0] != n)
            printf("%d", n);
        printf("\n");
        if(nprime.size() == 2 && nprime[0]*nprime[1] == n)
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}
