/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P2918 [USACO08NOV] Buying Hay S
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P2918
| When:    2023-07-29 08:50:48
| 
| Memory:  125 MB
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
    int n, h;
    cin>> n >> h;
    vector<int> p(n + 5), c(n + 5);
    for(int i = 1; i <= n; ++ i) {
        cin>> p[i] >> c[i];
    }
    // 完全背包
    vector<int> dp(h * 2 + 5, 0x3f3f3f3f);
    dp[0] = 0;
    for(int i = 1; i <= n; ++ i) {
        // 可能有多买，但是钱更少的情况
        for(int j = p[i]; j <= h * 2; ++ j) {
                dp[j] = min(dp[j], dp[j - p[i]] + c[i]);
        }
    }
    // 在符合情况里找最小
    for(int i = h; i <= h * 2; ++ i) {
        dp[h] = min(dp[h], dp[i]);
    }
    cout<< dp[h] <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
