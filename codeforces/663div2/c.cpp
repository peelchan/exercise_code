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

const ll mod = 1e9 + 7;

int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("data.out.txt","w",stdout);
#endif
    int n;
    scanf("%d", &n);
    ll prea = 2, preb = 0;
    ll nowa, nowb;
    for (int i = 3; i <= n; i++) {
        nowa = prea * i % mod;
        nowb = ((i - 2) * prea + 2 * preb) % mod;
        prea = nowa;
        preb = nowb;
    }
    printf("%I64d\n", preb);

    return 0;
}