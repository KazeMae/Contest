/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: World Fragments I
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57357/A
| When:    2023-07-24 12:36:10
| 
| Memory:  1048576 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    string x, y;
    ll a = 0, b = 0;
    cin>> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    for(int i = 0; i < x.size(); i++) {
        a += (x[i] == '1' ? (ll)pow(2ll, i) : 0);
    }
    for(int i = 0; i < y.size(); i++) {
        b += (y[i] == '1' ? (ll)pow(2ll, i) : 0);
    }
    if(a == 0 && a != b) cout<< -1;
    else cout<< abs(a - b);
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
