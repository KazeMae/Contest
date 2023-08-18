/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime 2023-07-21 15:18:40
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1000005; // 1e6 + 5

void solve() {
    int n, r, g, b;
    cin>> n >> r >> g >> b;
    if(n % 2) {
        int ans = r + g + b - 3;
        if(ans % 2) cout<< "Alice" <<endl;
        else cout<< "Bob" <<endl;
    }else cout<< "Alice" <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
