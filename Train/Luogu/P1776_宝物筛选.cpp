/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P1776 宝物筛选
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P1776
| When:    2023-07-27 02:15:48
| 
| Memory:  125 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, v, w, s;
    cin>> n >> m;
    vector<int> dp(m + 5);
    for(int i = 1; i <= n; i++) {
        cin>> w >> v >> s;
        for(int j = 0; j < v; j++) {
            deque<PII> q;
            for(int p = j, x = 1; p <= m; p += v, ++ x) {
                int e = dp[p] - x * w, r = x + s;
                while(!q.empty() && q.front().first <= e) q.pop_front();
                q.push_front({e, r});
                dp[p] = q.back().first + x * w;
                while(!q.empty() && q.back().second == x) q.pop_back();
            }
        }
    } 

    cout<< dp[m] <<endl;
}
