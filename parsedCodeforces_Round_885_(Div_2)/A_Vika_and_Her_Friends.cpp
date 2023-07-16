/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Vika and Her Friends
| Contest: Codeforces Round 885 (Div. 2)
| URL:     https://codeforces.com/contest/1848/problem/A
| When:    2023-07-16 22:37:30
| 
| Memory:  256 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
int v[N], u[N];
void solve() {
    int n, m, k;
    cin>> n >> m >> k;
    // cout<< n << ' ' << m << ' ' << k <<endl;
    int x, y;
    cin>> x >> y;
    for(int i = 0; i < k; i++) cin>> v[i] >> u[i];
    for(int i = 0; i < k; i++) {
        // cout<< abs(v - x) + abs(u - y) << " " << x << " " << y <<endl;
        if((abs(v[i] - x) + abs(u[i] - y)) % 2 == 0) {
            cout<< "NO" <<endl;
            return;
        }
    }
    cout<< "YES" <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
