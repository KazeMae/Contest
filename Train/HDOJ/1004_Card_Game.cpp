/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime 2023-07-20 20:55:49
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1000005; // 1e6 + 5
const int mod = 998244353;
int qmi(int m, int k, int p)
{
    int res = 1 % p, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}
void solve() {
    int n;
    cin>> n;
    cout<< qmi(2, n - 1, mod) - 1 <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
