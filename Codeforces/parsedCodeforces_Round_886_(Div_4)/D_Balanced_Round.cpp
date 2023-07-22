/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: D. Balanced Round
| Contest: Codeforces Round 886 (Div. 4)
| URL:     https://codeforces.com/contest/1850/problem/D
| When:    2023-07-21 22:52:14
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
    int n, k, sum = 0;
    cin>> n >> k;
    vector<int> a(n), ans;
    for(int i = 0; i < n; i++) {
        cin>> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(abs(a[i] - a[i - 1]) <= k) {
            cnt ++;
        }else {
            ans.push_back(cnt);
            cnt = 1;
        }
    }
    ans.push_back(cnt);
    sort(ans.begin(), ans.end());
    // for(auto i:a){
    //     cout<< i << " ";
    // }
    // cout<< endl;
    // for(auto i:ans) {
    //     cout<< i << " ";
    // }
    // cout<< endl;
    if(ans.size() == 1) cout<< 0 <<endl;
    else if(ans.size() == 2) cout<< min(n - ans.back(), ans.back()) <<endl;
    else cout<< n - ans.back() <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
