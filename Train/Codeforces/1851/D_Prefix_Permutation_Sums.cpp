/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: D. Prefix Permutation Sums
| Contest: Codeforces Round 888 (Div. 3)
| URL:     https://codeforces.com/contest/1851/problem/D
| When:    2023-07-25 22:51:51
| 
| Memory:  256 MB
| Time:    3000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, x = 0, y = 0, k = 0, e = 0, w = 0;
    cin>> n;
    map<long long, int> mp;
    vector<long long> a(n), v(n);
    for(int i = 1; i < n; ++ i) {
        cin>> a[i];
    }
    for(int i = 1; i < n; ++ i) {
        v[i] = a[i] - a[i - 1];
        mp[v[i]] ++;
        if(v[i] > n) w = v[i], k ++;
    }
    if(n == 2 && a[1] >= 1 && a[1] <= 3) {
        cout << "YES" <<endl;
        return;
    }
    for(int i = 1; i <= n; ++ i) {
        if(mp[i] > 1) k ++, w = i;
        if(mp[i] == 0) e ++, (x == 0 ? x = i : y = i);
    }
    if((w == 0 && x == n && y == 0) || (y == 0 && x >= 1 && x <= n)) cout << "YES" <<endl;
    else if(e > 2 || k > 1 || x + y != w) cout<< "NO" <<endl;
    else cout<< "YES" <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
