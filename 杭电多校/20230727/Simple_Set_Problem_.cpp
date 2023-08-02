/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Simple Set Problem 
| Contest: HDOJ
| URL:     https://acm.hdu.edu.cn/contest/problem?cid=1097&pid=1003
| When:    2023-07-27 15:03:12
| 
| Memory:  262144 MB
| Time:    3000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, m;
    cin>> n;
    vector<int> mn(n), mx(n);
    for(int i = 0 ; i < n; ++ i) {
        cin>> m;
        vector<int> se(m);
        for(int j = 0; j < m; ++ j) {
            cin>> se[j];
        }
        sort(se.begin(), se.end());
        mn.push_back(*se.begin());
        mx.push_back(se.back());
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
