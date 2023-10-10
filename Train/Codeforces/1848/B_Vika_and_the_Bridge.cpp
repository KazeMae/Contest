/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: B. Vika and the Bridge
| Contest: Codeforces Round 885 (Div. 2)
| URL:     https://codeforces.com/contest/1848/problem/B
| When:    2023-07-16 23:00:43
| 
| Memory:  256 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
int a[N];
void solve() {
    int n, k;
    cin>> n >> k;
    vector<vector<int> > km(k + 10);
    for(int i = 1; i <= n; i++) {
        cin>> a[i];
        km[a[i]].push_back(i);
    }
    int ans = 2e9, len;
    for(int i = 1; i <= k; i++) {
        if(km[i].size() == 0) continue;
        vector<int> v;
        v.push_back(km[i][0] - 1);
        for(int j = 1; j < km[i].size(); j ++) {
            v.push_back(km[i][j] - km[i][j - 1] - 1);
        }
        v.push_back(n - km[i][km[i].size() - 1]);
        sort(v.begin(), v.end());
        v[v.size() - 1] /= 2;
        sort(v.begin(), v.end());
        ans = min(v.back(), ans);
    }
    cout<< ans <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
