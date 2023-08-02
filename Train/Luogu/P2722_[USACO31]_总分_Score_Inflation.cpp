/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P2722 [USACO3.1] 总分 Score Inflation
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P2722
| When:    2023-07-29 02:53:07
| 
| Memory:  125 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int m, n;
    cin>> m >> n;
    vector<int> t(n + 5), s(n + 5);
    for(int i = 1; i <= n; ++ i) {
        cin>> s[i] >> t[i];
    }

    vector<int> dp(m + 5);
    for(int i = 1; i <= n; ++ i) {
        for(int j = t[i]; j <= m; ++ j) {
            dp[j] = max(dp[j], dp[j - t[i]] + s[i]);
        }
    }
    cout<< dp[m] <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
