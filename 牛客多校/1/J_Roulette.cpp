/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

// #define int long long
const int N = 1000005; // 1e6 + 5
const int MOD = 998244353;

ll qmi(ll m, ll k, ll p)
{
    ll res = 1 % p, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, m;
    cin>> n >> m, m += n;
    ll inv = 1ll * qmi(2, MOD - 2, MOD) % MOD;
    int k = 1;
    // 最大能输
    while ((int)pow(2, k) - 1 <= n) ++ k;
    ll res = 1;
    while (n < m) {
        // n为当前的左边界,r为当前的最大右边界
        ll r =  min((1ll << k) - 1, m);
        // 赢的概率 (1 - 输的概率)
        ll p = (1 - qmi(inv, k - 1, MOD) +  MOD) % MOD;
        res = (res * qmi(p, r - n, MOD)) % MOD;
        n = r;
        k ++;
    }
    cout<< res <<endl;
}
