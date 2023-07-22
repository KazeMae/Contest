/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         https://www.acwing.com/problem/content/899/
 * @DateTime    2023-07-21 21:01:09
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
    string a, b;
    cin>> a >> b;
    a = " " + a;
    b = " " + b;
    vector<vector<int> > dp(n + 3, vector<int> (m + 3));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if(a[i] == b[j]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    cout<< dp[n][m];
}
