/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P1048 [NOIP2005 普及组] 采药
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P1048
| When:    2023-07-27 02:21:52
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
    int t, n;
    cin>> t >> n;
    vector<int> v(n + 5), w(n + 5);
    vector<int> dp(t + 5);
    for(int i = 0; i < n; i++) {
        cin>> v[i + 1] >> w[i + 1];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = t; j >= v[i]; j --) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout<< dp[t] <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
