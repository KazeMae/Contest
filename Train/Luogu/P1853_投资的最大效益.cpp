/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P1853 投资的最大效益
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P1853
| When:    2023-07-29 08:11:33
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
    int s, n, d;
    cin>> s >> n >> d;
    vector<int> a(d + 5), b(d + 5);
    for(int i = 1; i <= d; ++ i) {
        cin>> a[i] >> b[i];
    }
    
    for(int i = 1; i <= n; ++ i) {
        vector<int> dp(s / 1000 + 50);
        for(int j = 1; j <= d; ++ j) {
            for(int k = a[j] / 1000; k <= s / 1000; ++ k) {
                dp[k] = max(dp[k], dp[k - a[j] / 1000] + b[j]);
            }
        }
        s += dp[s / 1000];
    }
    cout<< s <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
