/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @Url http://oj.daimayuan.top/problem/129
 * @DateTime 2023-07-21 19:54:41
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5
long long dp[1005][5];
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin>> n;
    dp[0][0] = 1, dp[0][1] = 1, dp[1][0] = 1, dp[1][1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < 2; j++) {
            dp[i][j] = dp[i - 1]
        }
    }
    cout<< dp[n];
}
