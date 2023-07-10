/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: E1. Rudolf and Snowflakes (simple version)
| Contest: Codeforces Round 883 (Div. 3)
| URL:     https://codeforces.com/contest/1846/problem/E1
| When:    2023-07-09 12:30:28
| 
| Memory:  256 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

#define int long long
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, k = 2;
    bool ans = 0;
    cin>>n;
    if(n < 7) {
        cout<< "No" <<endl;
        return;
    }
    for(int i = 2; 1 + i + i * i <= n; i++) {
        int res = 0;
        for(int j = 0; res <= n; j++) {
            if(res == n) {
                cout<< "Yes" <<endl;
                return;
            }else res += (int)pow(i, j);
        }
    }
    cout<< "No" <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
