#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n, fs = 0;
    cin>> n;
    std::vector<std::vector<int> > mp(n + 1, std::vector<int> (n + 1));
    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= n; ++ j) {
            cin>> mp[i][j];
            if(mp[i][j] < 0) fs += mp[i][j];
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; ++ i) {
        int mn = 1e7;
        for(int j = 1; j <= n; ++ j) {
            mn = min(mn, mp[i][j]);
        }
        cnt1 += max(mn, 0ll);
    }
    for(int i = 1; i <= n; ++ i) {
        int mn = 1e7;
        for(int j = 1; j <= n; ++ j) {
            mn = min(mn, mp[j][i]);
        }
        cnt2 += max(mn, 0ll);
    }
    cout<< min(cnt1, cnt2) + fs <<endl;
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
