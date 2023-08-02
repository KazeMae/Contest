/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         
 * @DateTime    2023-07-24 19:22:03
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

#define int long long
const int N = 1000005; // 1e6 + 5
int f[1010];
void exgcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1, y = 0;
        return;
    }
    if (b > a) return exgcd(b, a, y, x);
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k, x, y, s;
    f[0] = f[1] = 1;
    for (int i = 2; i < 98; ++i) f[i] = f[i - 1] + f[i - 2];
    cin>> n >> k;
    if (k > 88) {
        cout<< 0 <<endl;
    }else {
        exgcd(f[k - 3], f[k - 2], x, y);
        x *= n, y *= n;
        if (x < 0) s = (x + 1) / f[k - 2] - 1;
        else s = x / f[k - 2];
        x -= s * f[k - 2], y += s * f[k - 3];
        if (x <= y) cout<< max((y - x) / f[k - 1] + 1, 0ll) <<endl;
        else cout<< 0 <<endl;
    }
    return 0;
}
