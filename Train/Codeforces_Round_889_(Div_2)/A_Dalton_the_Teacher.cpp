/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Dalton the Teacher
| Contest: Codeforces Round 889 (Div. 2)
| URL:     https://codeforces.com/contest/1855/problem/A
| When:    2023-07-30 20:11:20
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
    int n, x, ans = 0;
    cin>> n;
    for(int i = 1; i <= n; ++ i) {
        cin>> x;
        if(x == i) ans ++;
    }
    cout<< ans / 2 + ans % 2 <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
