/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Insert 1, Insert 2, Insert 3, ...
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57362/H
| When:    2023-08-11 12:45:37
| 
| Memory:  1048576 MB
| Time:    4000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
const int MOD = 998244353;
 
void solve() {
    int n, ans = 0, mx = 0;
    cin>> n;
    vector<int> a(n + 1), d1, cnt(n + 2);
    for(int i = 0; i < n; ++ i) {
        cin>> a[i];
    }
    for(int i = 0; i < n; ++ i) {
        cnt[a[i]] ++;
        if(a[i] != 1) mx = max(mx, cnt[a[i]]);
        if(a[i] == 1) d1.push_back(i + 1);
        // cout<< " * " << d1.size() << " " << cnt[1] - cnt[a[i]] <<endl;
        if(a[i] == 1) {
            for(auto j:d1) {
                // cout<< j << " " << i + 1 <<endl;
                ans ++;
            }
        }else {
            // cout<< " * " << i + 1 << " " << d1.size() << " " << cnt[1] - mx << " " << mx <<endl;
            for(int j = 0; j <= cnt[1] - mx; ++ j) {
                // cout<< d1[j] << " " << i + 1 <<endl;
                ans ++;
            }
        }
        
    }
    cout<< ans <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
