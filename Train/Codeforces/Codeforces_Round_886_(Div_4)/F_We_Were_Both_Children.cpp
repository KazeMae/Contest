/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: F. We Were Both Children
| Contest: Codeforces Round 886 (Div. 4)
| URL:     https://codeforces.com/contest/1850/problem/F
| When:    2023-07-21 23:17:58
| 
| Memory:  256 MB
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
    int n;
    cin>> n;
    set<int> a;
    map<int, int> mp;
    vector<int> ct(N);
    for(int i = 0; i < n; i++) {
        int x;
        cin>> x;
        a.insert(x);
        mp[x] ++;
    }
    for(auto i:a) {
        int k = i;
        while(k <= n) {
            ct[k] += mp[i];
            k += i;
            // cout<< i << " " << k << " " << mp[k] <<endl;
        }
    }
    int ans = 0;
    // cout<< endl;
    // for(int i = 0; i <= n; i++) {
    //     cout<< i << " " << ct[i] <<endl;
    // }
    for(int i = 0; i <= n; i++) {
        ans = max(ans, ct[i]);
    }
    cout<< ans <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
