/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: D. Rudolph and Christmas Tree
| Contest: Codeforces Round 883 (Div. 3)
| URL:     https://codeforces.com/contest/1846/problem/D
| When:    2023-07-09 12:30:27
| 
| Memory:  256 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5

int y[N];
bool st[N];
void solve() {
    int n;
    double d, h;
    cin>> n >> d >> h;
    double si = h * d / 2, ans = 0;
    ans = si;
    for(int i = 0; i < n; i++) {
        cin>> y[i];
    }
    for(int i = 0; i < n - 1; i++) {
        if(y[i + 1] - y[i] >= h) {
            ans += si;
        }else {
            double x = d * (h - y[i + 1] + y[i]) / h;
            ans += (x + d) * (y[i + 1] - y[i]) / 2;
        }
    }
    printf("%lf\n", ans);
}
signed main () {
    // std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
