#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long
const int N = 1e5 + 5;


void solve() {
    cout<< setiosflags(ios::fixed) << setprecision(17);
    int n;
    cin>> n;
    double ans = n;
    vector<int> a(n + 1), q(n + 1);
    vector<double> prex(n + 1);
    for(int i  = 1; i <= n; ++ i) {
        cin>> a[i];
    }
    for(int i = 1; i <= n; ++ i) {
        cin>> q[i];
    }
    for(int i = 1; i <= n; ++ i) {
        double exp = i;
        if(q[i] == 0) continue;
        exp = (i - a[i]) * (1.0 / (q[i] / 100000.0) - 1) + i;
        ans = min(ans, exp);
    }
    cout<< ans <<endl;
}

signed main() {
     std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
