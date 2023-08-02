/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         https://www.acwing.com/problem/content/5/
 * @DateTime    2023-07-25 15:00:06
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin>> n >> m;
    vector<int> v(n + 5), w(n + 5), l(n + 5);
    for(int i = 0; i < n; i++) 
        cin>> v[i + 1] >> w[i + 1] >> l[i + 1];

    vector<int> dp(m + 5);
    // 二进制优化
    // 1, 2, 4, 8, 16,……, 2^m, n - 2^m + 1 可以实现每个数取一次得出所有[1, n]
    for(int i = 1; i <= n; i++) {
        int res = l[i];
        for(int k = 1; k <= res; res -= k, k *= 2) {
            for(int j = m; j >= v[i] * k; j--) {
                dp[j] = max(dp[j], dp[j - v[i] * k] + w[i] * k);
            }
        }
        for(int j = m; j >= v[i] * res; j--) {
            dp[j] = max(dp[j], dp[j - v[i] * res] + w[i] * res);
        }
    }
    cout<< dp[m] <<endl;
}
