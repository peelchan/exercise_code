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

int arr[maxn];

void generateArray(int n, int m, int seed) {
    unsigned x = seed;
    for(int i = 1; i <= n; i++) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        arr[i] = x % m + 1;
    }
}

int main()
{

    int n, m, seed;
    scanf("%d %d %d", &n, &m, &seed);

    generateArray(n, m, seed);

    priority_queue<ll, vector<ll>, greater<ll> > pq;
    for(int i = 1; i <= n; i++)
        pq.push(arr[i]);

    ll ans = pq.top();
    while(pq.size() >= 2) {
        ll x = pq.top();
        pq.pop();
        ll y = pq.top();
        pq.pop();
        if(x*2 >= y) {
            ans = max(ans, x*2);
            pq.push(x*2);
        } else {
            ans = max(ans, y);
            pq.push(y);
        }
    }
    printf("%lld\n", ans);

    return 0;
}

