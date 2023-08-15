/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         https://www.acwing.com/problem/content/4/
 * @DateTime    2023-07-25 14:33:39
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
    for(int i = 0; i < n; i++) {
        cin>> v[i + 1] >> w[i + 1] >> l[i + 1];
    }

    vector<int> dp(m + 5);
    for(int i = 1; i <= n; i++) {
        for(int k = 1; k <= l[i]; k++) {
            for(int j = m; j >= v[i]; j --) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
    }
    cout<< dp[m] <<endl;
}
