/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: D. Strong Vertices
| Contest: Codeforces Round 891 (Div. 3)
| URL:     https://codeforces.com/contest/1857/problem/D
| When:    2023-08-08 00:46:17
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
const int MOD = 998244353;
 
void solve() {
    int n;
    cin>> n;
    vector<int> a(n), b(n), ans;
    vector<PII> x(n);
    for(int i = 0; i < n; i++) cin>> a[i];
    for(int i = 0; i < n; i++) cin>> b[i], x[i] = {a[i] - b[i], i + 1};

    sort(x.begin(), x.end());
    
    for(int i = 0; i < n; ++ i) {
        if(x[i].first == x.back().first) ans.push_back(x[i].second);
    }
    cout<< ans.size() <<endl;
    for(auto i:ans) cout<< i <<" "; cout<<endl;

}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
