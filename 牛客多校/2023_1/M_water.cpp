/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime 2023-07-20 01:25:59
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1000005; // 1e6 + 5

// 求x, y，使得ax + by = gcd(a, b)
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;
    return d;
}

void solve() {
    int a, b, x;
    cin>> a >> b >> x;
    int k1, k2, ans = 1e18;
    int d = exgcd(a, b, k1, k2);
    if(x % d != 0) {
        cout<< -1 <<endl;
        return;
    }
    a /= d, b /= d, x /= d;
    k1 = (k1 * x % b + b) % b;
    k2 = (x - k1 * a) / b;
    for (int t = -10; t <= 10; t++) {
        int r = k1 + b * t, s = k2 - a * t;
        if (r >= 0 && s >= 0) {
            ans = min(ans, 2 * (r + s));
        } else {
            ans = min(ans, 2 * abs(r - s) - 1);
        }
    }
    cout<< ans <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
