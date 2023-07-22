/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Subtraction Game
| Contest: Codeforces Round  884 (Div. 1 + Div. 2)
| URL:     https://codeforces.com/contest/1844/problem/A
| When:    2023-07-11 22:35:14
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
    int a, b;
    cin>> a >> b;
    if(a > b) swap(a, b);
    if(2 * a < b) cout<< a * 2 <<endl;
    else if(2 * a >= b) cout<< a + b <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
