/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: F. Sum and Product
| Contest: Codeforces Round 891 (Div. 3)
| URL:     https://codeforces.com/contest/1857/problem/F
| When:    2023-08-08 00:40:51
| 
| Memory:  256 MB
| Time:    4000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
const int MOD = 998244353;
 
int f(int n) {
    int sum = 0;
    for(int i = 1; i < n; i++) sum += i;
    return sum;
}

void solve() {
    int n, q;
    cin>> n;
    vector<int> a(n);
    map<int, int> mp; 
    for(int i = 0; i < n; ++ i) {
        cin>> a[i];
        mp[a[i]] ++;
    }
    cin>> q;
    while(q --) {
        int x, y;
        cin>> x >> y;
        int det = x * x - 4 * y;
        // cout<< sqrt(det) << " " << (x + (int)sqrt(det)) / 2 << " " << (x - (int)sqrt(det)) / 2 << " *";
        if((int)sqrt(det) * (int)sqrt(det) != det) cout<< 0 << " ";
        else if((x + (int)sqrt(det)) / 2 == (x - (int)sqrt(det)) / 2) cout<< f(mp[(x + (int)sqrt(det)) / 2]) << " ";
        else cout<< mp[(x + (int)sqrt(det)) / 2] * mp[(x - (int)sqrt(det)) / 2] << " ";
    // cout<<endl;

    }
    cout<<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
