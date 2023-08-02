/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P1164 小A点菜
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P1164
| When:    2023-07-27 02:36:47
| 
| Memory:  128 MB
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
    int n, m;
    cin>> n >> m;
    vector<int> a(n + 5);
    for(int i = 1; i <= n; ++ i) {
        cin>> a[i];
    }

    vector<int> dp(m + 5);
    dp[0] = 1;
    for(int i = 1; i <= n; ++ i) {
        for(int j = m; j >= a[i]; -- j) {
            dp[j] = max(dp[j], dp[j - a[i]] + dp[j]);
        }
    }
    cout<< dp[m] <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
