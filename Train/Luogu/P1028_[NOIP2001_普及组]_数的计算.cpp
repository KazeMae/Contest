/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P1028 [NOIP2001 普及组] 数的计算
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P1028
| When:    2023-07-29 01:59:58
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

int ans;

void dfs(int n) {
    if(n >= 1) ans ++;
    if(n == 1) return;
    for(int i = n / 2; i > 0; -- i) dfs(i);
}

void solve() {
    int n;
    cin>> n;
    dfs(n);
    cout<< ans <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
