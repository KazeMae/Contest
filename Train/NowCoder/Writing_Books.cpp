/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Writing Books
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57361/M
| When:    2023-08-07 12:17:21
| 
| Memory:  524288 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
const int MOD = 998244353;
 
void solve() {
    int n, ws = 0, m, sum = 0, k = 9, i = 1, mm = 9;
    cin>> n;
    m = n;
    while(m > 0) {
        m /= 10, ws ++;
    }
    for(i = 1; i < ws; ++ i) {
        sum += k * i, k *= 10, mm = mm * 10 + 9;
    }
    // cout<< sum << " " << mm <<endl;
    cout<< sum + (n - mm / 10) * i <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
