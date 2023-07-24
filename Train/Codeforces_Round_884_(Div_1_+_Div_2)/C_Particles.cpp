/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C. Particles
| Contest: Codeforces Round  884 (Div. 1 + Div. 2)
| URL:     https://codeforces.com/contest/1844/problem/C
| When:    2023-07-11 23:47:37
| 
| Memory:  256 MB
| Time:    1000 ms
*******************************/
/**
 * WA
 */
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
int a[N];
void solve() {
    int n, x, sum = 0, mn = -2e9;
    cin>> n;
    for(int i = 0; i < n; i++) {
        cin>> a[i];
        mn = max(mn, a[i]);
    }
    int j = 0, o = 0;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            if(a[i] >= 0)
                j += a[i];
            else if(a[i] > j) j = a[i];
        }else {
            if(a[i] >= 0)
                o += a[i];
            else if(a[i] > o) o = a[i];
        }
    }
    // cout<< j << " " << o <<endl;
    if(j != 0 || o != 0) {
        cout<< max(j, o) <<endl;
    }else cout<< mn <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
