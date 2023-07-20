/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Hossam and Combinatorics
| Contest: Codeforces Round 837 (Div. 2)
| URL:     https://codeforces.com/contest/1771/problem/A
| When:    2023-07-12 22:59:46
| 
| Memory:  256 MB
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
    int n, x, mi = 2e9, mx = 0;
    map<int, int> mp;
    cin>> n;
    for(int i = 0; i < n; i++) {
        cin>> x;
        mx = max(x, mx), mi = min(x, mi);
        mp[x] ++;
    }
    if(mx == mi) cout<< mp[mx] * (mp[mx] - 1) <<endl;
    else cout<< mp[mx] * mp[mi] * 2 <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
