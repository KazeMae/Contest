/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Tales of a Sort
| Contest: Codeforces Round 890 (Div. 2) supported by Constructor Institute
| URL:     https://codeforces.com/contest/1856/problem/A
| When:    2023-08-06 14:41:02
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

void solve() {
    int n, mx = 0;
    cin>> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin>> a[i], (i != 0 && a[i] < a[i - 1] ? mx = max(a[i - 1], mx) : 0);
    cout<< mx <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
