/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P1060 [NOIP2006 普及组] 开心的金明
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P1060
| When:    2023-07-28 17:09:49
| 
| Memory:  64 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, m, x;
    cin>> n >> m;
    vector<int> v(m + 5), w(m + 5);
    vector<int> dp(n + 5);
    for(int i = 0; i < m; ++ i) {
        cin>> v[i + 1] >> x;
        w[i + 1] = v[i + 1] * x;
    }

    for(int i = 1; i <= m; ++ i) {
        for(int j = n; j >= v[i]; -- j) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            // cout<< i << " " << j << " " << dp[j] << endl;
        }
    }
    cout<< dp[n] <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
