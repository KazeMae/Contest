/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         http://scpc.fun/group/1003/problem/WAM480002/full-screen
 * @DateTime    2023-07-28 02:12:03
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

#define int long long
const int N = 1000005, inf = 0x3f3f3f3f; // 1e6 + 5

main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin>> n;
    vector<int> a(n + 1), dp(n + 1);
    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= i; ++ j) cin>> a[j];
        for(int j = i; j >= 1; -- j) 
            dp[j] = min(dp[(j - 1 == 0 ? 1 : j - 1)] + a[j], dp[(j == i ? j - 1 : j)] + a[j]), (i == n ? dp[n] = min(dp[j], dp[n]) : dp[n] = dp[n]);
    }
    cout<< dp[n] <<endl;
}
