/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: 找孙子
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/62880/M
| When:    2023-08-02 21:55:04
| 
| Memory:  524288 MB
| Time:    4000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
int ans = 0;
vector<int> e[N];
vector<bool> st(N);
void dfs(int x, int k) {
    if(st[x] || k > 2) return;
    if(k == 2) {
        ans ++;
        return;
    }
    st[x] = 1;
    for(auto i:e[x]) {
        dfs(i, k + 1);
    }
    st[x] = 0;
}

void solve() {
    int n, m;
    cin>> n >> m;
    for(int i = 0; i < m; ++ i) {
        int u, v;
        cin>> u >> v;
        e[u].push_back(v);
    }

    for(int i = 1; i <= n; ++ i) {
        ans = 0;
        dfs(i, 0);
        cout<< ans <<" ";
    }

}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
