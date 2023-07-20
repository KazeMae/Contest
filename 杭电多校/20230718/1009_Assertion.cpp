/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime
 * @RunID 976
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1000005; // 1e6 + 5

void solve() {
    int n, m, d;
    cin>> n >> m >> d;
    if(m / n + (m % n != 0) >= d) cout<< "Yes" <<endl;
    else cout<< "No" <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
