/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: 入门mex
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/62332/B
| When:    2023-07-26 15:08:41
| 
| Memory:  524288 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

inline void solve() {
    int n, k, x;
    cin>> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>> a[i];
    }
    sort(a.begin(), a.end());
    int m = unique(a.begin(), a.end()) - a.begin();
    // cout<< n <<endl;
    for(int i = 0; i < m; i++) {
        // cout<< a[i] << " " << i <<endl;
        if(a[i] != i) {
            x = i;
            break;
        }
    }
    if(x > k) cout<< k <<endl;
    else cout<< x <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
