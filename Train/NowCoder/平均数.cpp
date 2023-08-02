/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: 平均数
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/62880/E
| When:    2023-08-02 21:29:41
| 
| Memory:  524288 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, s;
    cin>> n >> s;
    int k = s / n;
    for(int i = 0; i < n - (s - k * n); ++ i) cout<< k << " ";
    for(int i = n - (s - k * n); i < n; ++ i) cout<< k + 1 << " ";
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
