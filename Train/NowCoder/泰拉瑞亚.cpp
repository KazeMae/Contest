/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: 泰拉瑞亚
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/62332/L
| When:    2023-07-26 15:21:33
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
    int n, h, sum = 0, ans = 0, mx = 0;
    bool flag = 0;
    cin>> n >> h;
    vector<PII> a(n);
    for(int i = 0; i < n; i++) {
        cin>> a[i].first >> a[i].second;
        mx = max(mx, a[i].first);
    }
    for(int i = 0; i < n; i++) {
        if(a[i].second >= mx) sum += a[i].second, ans ++;
        if(sum >= h) {
            break;
        }
    }
    // cout<< sum << " " << ans << " " << mx << " " << (h - ) / mx <<endl;
    if(sum >= h) {
        cout<< ans <<endl;
    }else {
        cout<< ans + (h - sum) / mx + ((h - sum) % mx != 0) <<endl;
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
