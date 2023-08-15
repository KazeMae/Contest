/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C. Another Permutation Problem
| Contest: Codeforces Round 892 (Div. 2)
| URL:     https://codeforces.com/contest/1859/problem/C
| When:    2023-08-12 23:58:11
| 
| Memory:  256 MB
| Time:    3000 ms
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
    int n, mx = 0;
    ll sum = 0;
    cin>> n;
    for(int i = 1; i <= n; ++ i) {
        cout<< i << " : ";
        sum += i * i;
        for(int j = 1; j <= n; ++ j) {
            cout<< i * j << " ";
        }
        cout<< endl;
    }
    cout<< sum <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
