/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         https://www.acwing.com/problem/content/284/
 * @DateTime    2023-08-10 22:48:59
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
    int n;
    cin>> n;
    vector<int> a(n + 1), s(n + 1);
    for(int i = 0; i < n; ++ i) {
        cin>> a[i + 1];
        s[i + 1] = s[i] + a[i + 1];
    }
    
    vector<vector<int> > dp(n + 1, vector<int> (n + 1, 2e9));

    for(int i = 1; i <= n; ++ i) 
        dp[i][i] = 0;
    for(int i = 1; i < n; ++ i) // 区间长度
        for(int j = 1; j <= n - i; ++ j) // 起始位置
            for(int k = j; k < j + i; ++ k) // 区间中的分割点
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + s[j + i] - s[j - 1]);

    cout<< dp[1][n] <<endl;
}
