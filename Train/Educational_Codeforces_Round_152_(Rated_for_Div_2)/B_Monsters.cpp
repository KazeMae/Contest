/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: B. Monsters
| Contest: Educational Codeforces Round 152 (Rated for Div. 2)
| URL:     https://codeforces.com/contest/1849/problem/B
| When:    2023-07-27 22:39:06
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
    int n, k;
    cin>> n >> k;
    vector<PII> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin>> x;
        a.push_back({(x % k != 0 ? x % k : k), n - i});
        // cout<< x <<endl;
    }
    sort(a.begin(), a.end());
    // int m = 0;
    // for(m; m < n; ++ m) {
    //     if(a[m].first == 0) {
    //         cout<< n - a[m].second + 1 << " ";
    //     }else break;
    // }
    for(int i = n - 1; i >= 0; -- i) {
        cout<< n - a[i].second + 1 <<" ";
    }
    cout<<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
