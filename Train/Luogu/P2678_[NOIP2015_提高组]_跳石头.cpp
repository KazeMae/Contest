/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P2678 [NOIP2015 提高组] 跳石头
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P2678
| When:    2023-07-29 02:08:52
| 
| Memory:  128 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
vector<int> a(N);
int L, n, m;
bool check(int mid) {
    int res = 0, w = 0;
    for(int i = 1; i <= n + 1; ++ i) {
        if(a[i] - a[w] < mid) res ++;
        else w = i;
    }
    return res > m;
}

void solve() {
    cin>> L >> n >> m;
    for(int i = 1; i <= n; ++ i) {
        cin>> a[i];
    }
    a[n + 1] = L;
    int l = 0, r = L;
    while(l < r) {
        int mid = l + r + 1>> 1;
        if(check(mid)) r = mid - 1;
        else l = mid;
    }
    cout<< r <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
