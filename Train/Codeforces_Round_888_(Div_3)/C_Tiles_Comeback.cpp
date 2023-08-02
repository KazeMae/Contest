/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C. Tiles Comeback
| Contest: Codeforces Round 888 (Div. 3)
| URL:     https://codeforces.com/contest/1851/problem/C
| When:    2023-07-25 22:51:50
| 
| Memory:  256 MB
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
    int n, k, x, y;
    cin>> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin>> a[i];
    }
    if(a[0] != a[n - 1]) {
        int i = 0;
        for(i; i < n; i++) {
            if(a[i] == a[0]) mp[a[i]] ++;
            if(mp[a[0]] >= k) break;
        }
        for(i; i < n; i++) {
            if(a[i] == a[n - 1]) mp[a[i]] ++;
            if(mp[a[n - 1]] >= k) break;
        }
        cout<< (mp[a[n - 1]] >= k && mp[a[0]] >= k ? "YES" : "NO") <<endl;
    }else {
        for(int i = 0; i < n; i++) {
            mp[a[i]] ++;
        }
        cout<< (mp[a[0]] >= k ? "YES" : "NO") <<endl;
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
