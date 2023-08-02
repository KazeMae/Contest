/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: 完全平方数
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/62332/E
| When:    2023-07-26 14:58:17
| 
| Memory:  524288 MB
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
    int n, a, sum = 0, ans = 0;
    cin>> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin>> a;
        mp[a] ++;
        sum = max(a, sum);
    }
    for(int i = 1; i * i <= sum; i++) {
        ans += mp[i * i];
    }
    cout<< ans <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
