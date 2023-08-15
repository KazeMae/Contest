/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P8872 [传智杯 #5 初赛] D-莲子的物理热力学
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P8872
| When:    2023-08-08 20:15:12
|
| Memory:  512 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
const int MOD = 998244353;

void solve() {
    int n, m, unmic = 0, unmxc = 0;
    cin>> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++ i) 
        cin>> a[i];
    int mi = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());
    for(auto i:a) {
        if(i != mi) unmic ++;
        if(i != mx) unmxc ++;
    }
    sort(a.begin(), a.end());
    if(unmic <= m || unmxc <= m) cout<< 0 <<endl;
    else {
        int ans = 2e9;
        for(int i = 0; i < n; i++) {
            int k = m - i * 2;
            if(k < 0) break;
            else if(k == 0) ans = min(ans, a[n - 1] - a[i]);
            else ans = min(ans, a[n - i - k] - a[i]);
            // cout<< "+ " << i << " " << k << " " << ans << " " << a[n - i - k] - a[i] << endl;
        }
        for(int i = n - 1; i >= 0; -- i) {
            int k = m - (n - i - 1) * 2;
            if(k < 0) break;
            else if(k == 0) ans = min(ans, a[i] - a[0]);
            else ans = min(ans, a[i] - a[k]);
            // cout<< "- " << i << " " << k << " " << ans << " " << a[i] - a[k] << endl;
        }
        cout<< ans <<endl;
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
    solve();
}
