/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Go to Play Maimai DX
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57359/G
| When:    2023-07-31 12:06:15
| 
| Memory:  524288 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, k;
    cin>> n >> k;
    vector<int> a(n + 1), d;
    for(int i = 0; i < n; i++) {
        cin>> a[i];
    }
    int ans = 2e5, l = 0, r = 0;
    vector<int> cnt(5);
    cnt[a[r]] ++;
    for(l;l < n;) {
        if(cnt[4] >= k && cnt[1] >= 1 && cnt[2] >= 1 && cnt[3] >= 1)
            ans = min(ans, r - l + 1), cnt[a[l ++]] --;
        else if(r < n - 1)
            cnt[a[++ r]] ++;
        else if(l < n - 1)
            cnt[a[l ++]] --;
        else break;
        // cout<< l << " " << r <<endl;
    }
    cout<< ans <<endl;
}
signed main () {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
