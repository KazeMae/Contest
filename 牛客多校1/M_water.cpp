/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime  2023-07-17 12:11:04
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1000005; // 1e6 + 5

void solve() {
    int a, b, x, q, w, ans = 1;
    cin>> a >> b >> x;
    if(a > b) swap(a, b);

    // 求x约数
    map<int, bool> ys;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0) {
            ys[i] = 1;
            if (i != x / i) ys[x / i] = 1;
        }

    if(ys[a]) cout << x / a <<endl;
    else if(ys[b]) cout<< x / b <<endl;
    else {
        q = a, w= b;
        while (q < w) {
            w -= q;
            ans += 2;
            if(ys[w]) break;
        }
        if(ys[w] == 0) cout<< -1 <<endl;
        else cout<< (x / w) * ans <<endl;
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
