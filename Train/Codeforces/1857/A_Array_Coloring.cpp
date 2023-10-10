/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Array Coloring
| Contest: Codeforces Round 891 (Div. 3)
| URL:     https://codeforces.com/contest/1857/problem/A
| When:    2023-08-07 22:37:06
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
const int MOD = 998244353;
 
void solve() {
    int n, a, ans = 0;
    cin>> n;
    for(int i = 0; i < n; i++) {
        cin>> a;
        if(a % 2) ans ++;
    }
    cout<< (ans % 2 ? "NO" : "YES") <<endl;

}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
