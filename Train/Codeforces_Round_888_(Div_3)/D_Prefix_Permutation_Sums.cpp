/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: D. Prefix Permutation Sums
| Contest: Codeforces Round 888 (Div. 3)
| URL:     https://codeforces.com/contest/1851/problem/D
| When:    2023-07-25 22:51:51
| 
| Memory:  256 MB
| Time:    3000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, k = 0;
    cin>> n;
    map<int, int> mp;
    vector<ll> a(n), b, c;
    for(int i = 0; i < n - 1; i++) {
        cin>> a[i];
        if(i != 0) b.push_back(a[i] - a[i - 1]);
        else b.push_back(a[i]);
    }
    int x = 0, y = 0;
    sort(b.begin(), b.end());
    for(int i = 1; i <= n; i++) {
        if(i != *--upper_bound(b.begin(), b.end(), i)) {
            if(x == 0) {
                x = i;
            }else {
                y = i;
                break;
            }
        }
    }
    for(auto i:b) {
        mp[i] ++;
        if(mp[i] > 1 || i >= n) c.push_back(i);
    }
    // if(x + y == b.back()) k = 1;
    for(auto i:c) {
        // cout<< i << " ";
        if(x + y == i) k = 1;
    }
    // cout<<endl;
    // cout<< x << " " << y << " " << k <<endl;
    if(y == 0 && k == 0) cout<< "YES" <<endl;
    else if(k >= 1) cout<< "YES" <<endl;
    else cout<< "NO" <<endl;

}
signed main () {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
