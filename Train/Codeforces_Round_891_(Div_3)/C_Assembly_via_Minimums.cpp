/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C. Assembly via Minimums
| Contest: Codeforces Round 891 (Div. 3)
| URL:     https://codeforces.com/contest/1857/problem/C
| When:    2023-08-07 23:10:19
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
    vector<int> b((n * (n - 1) / 2)), a;
    a.push_back(0);
    for(int i = n - 1; i >= 1; -- i) {
        a.push_back(i);
    }
    for(int i = 0; i < (n * (n - 1) / 2); ++ i) 
        cin>> b[i];
    sort(b.begin(), b.end());
    int k = 0;
    // for(auto i:a) cout<< i <<" ";cout<<endl;
    for(int i = 0; i < n - 1; i++) {
        cout<< b[k + a[i]] << " ";
        k += a[i];
    }
    cout<< b.back() << endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
