/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P1049 [NOIP2001 普及组] 装箱问题
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P1049
| When:    2023-07-27 02:32:21
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
    vector<int> v(n + 5);

    for(int i = 1; i <= n; i++) {
        cin>> v[i];
    }

    vector<int> dp(m + 5);
    for(int i = 1; i <= n; ++ i) {
        for(int j = m; j >= v[i]; -- j) {
            dp[j] = max(dp[j], dp[j - v[i]] + v[i]);
        }
    }
    cout<< m - dp[m] <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
