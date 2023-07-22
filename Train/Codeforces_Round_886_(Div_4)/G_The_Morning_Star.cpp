/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: G. The Morning Star
| Contest: Codeforces Round 886 (Div. 4)
| URL:     https://codeforces.com/contest/1850/problem/G
| When:    2023-07-21 23:51:20
| 
| Memory:  256 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, u, v;
    ll sum = 0;
    cin>> n;

    map<int, int> x, y;
    map<pair<int, int>, int> ds, sd;
    set<PII> uv;

    for(int i = 0; i < n; i++) {
        cin>> u >> v;
        uv.insert({u, v});
        x[u] ++, y[v] ++, ds[{0, v - u}] ++, sd[{0, u + v}] ++;
    }

    // for(auto i:x){
    //     cout<< "x" << " " << i.first<< " " << i.second <<endl;
    // }
    // cout<< endl;
    // for(auto i:y){
    //     cout<< "y" << " " << i.first<< " " << i.second <<endl;
    // }
    // cout<< endl;
    // for(auto i:ds){
    //     cout<< "ds" << " " << i.first.first << " " << i.first.second << " " << i.second <<endl;
    // }
    // cout<< endl;

    for(auto i:uv) {
        sum += x[i.first] - 1;
        sum += y[i.second] - 1;
        sum += ds[{0, i.second - i.first}] - 1;
        sum += sd[{0, i.first + i.second}] - 1;
        // cout<< i.first << " " << i.second << " " <<  sum << endl;
    }
    cout<< sum <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
