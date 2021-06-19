#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x3f3f3f3f;
const int maxn = 400010;
#define pr(x) cout << #x << " = " << x << " ";
#define prln(x) cout << #x << " = " << x << " " << endl;

const int mod = 998244353;

int l[maxn], r[maxn];
ll fac[maxn], inv[maxn];

ll mul(ll a, ll b) { return a * b % mod; }

ll myPow(ll x, ll y) {
    if (y == 0) return 1;
    ll ans = myPow(x, y >> 1);
    ans = mul(ans, ans);
    if (y & 1) ans = mul(ans, x);
    return ans;
}

void init(int k) {
    fac[0] = 1;
    for (int i = 1; i <= k; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[k] = myPow(fac[k], mod - 2);
    for (int i = k - 1; i >= 0; i--) {
        inv[i] = mul(inv[i + 1], i + 1);
    }
}

ll get(int n, int k) {
    if (n < k) return 0;
    return mul(fac[n], mul(inv[n - k], inv[k]));
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    init(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &l[i], &r[i]);
    }
    sort(l, l + n);
    sort(r, r + n);
    int now = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        while (now < n && r[now] < l[i]) now++;
        ans = (ans + get(i - now, k - 1)) % mod;
    }
    printf("%I64d\n", ans);
    return 0;
}