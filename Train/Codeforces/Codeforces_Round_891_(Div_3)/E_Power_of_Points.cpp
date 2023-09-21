/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: E. Power of Points
| Contest: Codeforces Round 891 (Div. 3)
| URL:     https://codeforces.com/contest/1857/problem/E
| When:    2023-08-07 23:41:25
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
const int MOD = 998244353;
 
void solve() {
    int n;
    cin>> n;
    map<int, int> mp, cnt;
    vector<int> b(n), s;
    for(int i = 0; i < n; i++) {
        cin>> b[i];
        cnt[b[i]] ++;
        if(cnt[b[i]] == 1) s.push_back(b[i]);
    }
    sort(s.begin(), s.end());
    int ans = 0, k = 0;
    for(int i = 0; i < s.size(); i ++) {
        ans += (s[i] - s[0] + 1) * cnt[s[i]];
    }
    k += cnt[s[0]];
    // cout<< k <<endl;
    mp[s[0]] = ans;
    for(int i = 1; i < s.size(); i++) {
        ans += (s[i] - s[i - 1]) * k;
        ans -= (s[i] - s[i - 1]) * cnt[s[i]];
        ans -= (s[i] - s[i - 1]) * (n - k - cnt[s[i]]);
        mp[s[i]] = ans;
        k += cnt[s[i]];
    }
    for(auto i:b) cout<< mp[i] << " "; cout<<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
