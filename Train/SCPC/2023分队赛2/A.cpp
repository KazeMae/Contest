#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

#define int long long
const int N = 10005; // 1e6 + 5


void solve();
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t, ct = 0, xf = 0;
    cin>> t;
    for(int i = 0; i < t; ++ i) {
        int n, f, ef = 0;
        cin>> n >> f;
        for(int i = 0, u, v; i < n - 1; ++ i) 
            cin>> u >> v, ef += (u == f || v == f);
        // cout << ef << " " << (n - ef - 1) <<endl;
        if(ef <= 1) ct += 1;
        else if((n - 1) % 2) ct += 1;
        else xf += 1;
    }
    cout << ct - xf <<endl;
}
