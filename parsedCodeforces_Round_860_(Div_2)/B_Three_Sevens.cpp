/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: B. Three Sevens
| Contest: Codeforces Round 860 (Div. 2)
| URL:     https://codeforces.com/contest/1798/problem/B
| When:    2023-07-14 15:59:02
| 
| Memory:  256 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
int a[N];
void solve() {
    int m;
    cin>> m;
    for(int k = 0; k < m; k++) {
        int n;
        cin>> n;
        for(int i = 0; i < n; i++) {
            cin>> a[i];
        }
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
