/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Morning Sandwich
| Contest: Educational Codeforces Round 152 (Rated for Div. 2)
| URL:     https://codeforces.com/contest/1849/problem/A
| When:    2023-07-27 22:35:58
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
    int b, c, h;
    cin>> b >> c >> h;
    if(b == 2) cout<< 3 <<endl;
    else {
        cout<< min({b - 1, c + h}) * 2 + 1 <<endl;
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
