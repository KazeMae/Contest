/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime 2023-07-21 16:25:29
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1000005; // 1e6 + 5

void solve() {
    int n, m, k, x;
    cin>> n >> m >> k;

    vector<priority_queue<PII> > a(n + 1);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin>> x;
            a[i].push({x, j});
        }
    }
    int cnt = k % n;
    cnt == 0 ? cnt = n : cnt;
    set<int> ans;

    while(k --) {
        while (ans.count(a[cnt].top().second) != 0) {
            a[cnt].pop();
        }
        ans.insert(a[cnt].top().second);
        a[cnt].pop();
        -- cnt;
        cnt == 0 ? cnt = n : cnt;
    }
    for(auto i:ans) {
        cout<< i <<" ";
    }
    cout<<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
