/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: PSO
| Contest: HDOJ
| URL:     https://acm.hdu.edu.cn/contest/problem?cid=1097&pid=1006
| When:    2023-07-27 15:29:10
| 
| Memory:  65536 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n;
    cin>> n;
    if(n == 2) {
        cout<< "1.000000000 1.000000000" <<endl;
        return;
    }
    double x = 2.0 * ((double)(n - 2) / n) + 1.0 - ((double)(n - 2) / n);
    printf("%.9lf 2.000000000\n", x);
}
signed main () {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
