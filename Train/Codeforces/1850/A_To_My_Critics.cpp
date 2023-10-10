/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. To My Critics
| Contest: Codeforces Round 886 (Div. 4)
| URL:     https://codeforces.com/contest/1850/problem/A
| When:    2023-07-21 22:35:27
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
    int a, b ,c;
    cin>> a >> b >> c;
    if(a + b >= 10) cout<< "YEs" <<endl;
    else if(b + c >= 10) cout<< "YES" <<endl;
    else if(a + c >= 10) cout<< "YES" <<endl;
    else cout<< "NO" <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
