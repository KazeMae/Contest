/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: 滑动窗口
| Contest: AcWing
| URL:     https://www.acwing.com/problem/content/156/
| When:    2023-07-26 02:34:59
| 
| Memory:  64 MB
| Time:    1000 ms
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
    vector<int> a(n + 5), ansn, ansx;
    for(int i = 1; i <= n; i++) {
        cin>> a[i];
    }

    deque<PII> q;
    for(int i = 1; i <= n; i++) {
        while(!q.empty() && q.front().first >= a[i]) q.pop_front();
        q.push_front({a[i], i});
        if(i >= k) ansn.push_back(q.back().first);
        while(!q.empty() && q.back().second <= i - k + 1) q.pop_back();
    }
    q.clear();
    for(int i = 1; i <= n; i++) {
        while(!q.empty() && q.front().first <= a[i]) q.pop_front();
        q.push_front({a[i], i});
        if(i >= k) ansx.push_back(q.back().first);
        while(!q.empty() && q.back().second <= i - k + 1) q.pop_back();
    }

    for(auto i:ansn) cout<< i << " "; 
        cout<<endl;
    for(auto i:ansx) cout<< i << " "; 
        cout<<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
