/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: B. Fibonaccharsis
| Contest: Codeforces Round 887 (Div. 2)
| URL:     https://codeforces.com/contest/1853/problem/B
| When:    2023-07-23 22:42:57
| 
| Memory:  256 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

// typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, k;
    cin>> n >> k;
    if(k > 28) {
        cout<< 0 <<endl;
        return;
    }
    int ans = 0;
    for(int i = n; i >= 1; i--) {
        int x = i, y = n;
        bool flag = 1;
        for(int j = 0; j < k - 2; j ++) {
            int t = y - x;
            if(x < 0|| t > x) {
                flag = 0;
                break;
            }
            y = x;
            x = t;
        }
        if(flag) ans ++;
    }
    cout<< ans <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
