/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: D. Row Major
| Contest: Codeforces Round  884 (Div. 1 + Div. 2)
| URL:     https://codeforces.com/contest/1844/problem/D
| When:    2023-07-12 22:19:37
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
    int n;
    cin>> n;
    int k = 1;
    while(n % k == 0) {
        k ++;
    }
    // cout<< k <<endl;
    for (int i = 0; i < n; ++i)
    {
        cout << (char)('a' + i % k);
    }
    cout<<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
