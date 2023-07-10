/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Rudolph and Cut the Rope 
| Contest: Codeforces Round 883 (Div. 3)
| URL:     https://codeforces.com/contest/1846/problem/A
| When:    2023-07-09 12:30:24
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

void solve() {
    int n, a, b, ans = 0;
    cin>> n;
    for(int i = 0; i < n; i++) {
        cin>> a >> b;
        if(b < a) ans ++;
    }
    cout<< ans <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
