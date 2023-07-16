/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Showstopper
| Contest: Codeforces Round 860 (Div. 2)
| URL:     https://codeforces.com/contest/1798/problem/A
| When:    2023-07-14 14:37:13
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
int a[N], b[N];
void solve() {
    int n, mxa = 0, mxb = 0;
    cin>> n;
    for(int i = 0; i < n; i++) {
        cin>> a[i];
        mxa = max(mxa, a[i]);
    }
    for(int i = 0; i < n; i++) {
        cin>> b[i];
        mxb = max(mxb, b[i]);
    }
    bool flag = true;
    for(int i = 0; i < n; i++) {
        if(a[i] > a[n - 1] && (b[i] > a[n - 1] || a[i] > b[n - 1])) {
            flag = false;
        }
        if(b[i] > b[n - 1] && (a[i] > b[n - 1] || b[i] > a[n - 1])) {
            flag = false;
        }
    }
    cout<< (flag ? "YES" : "NO") <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
