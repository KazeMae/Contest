/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         https://www.acwing.com/problem/content/284/
 * @DateTime    2023-08-10 22:30:45
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5

inline int solve(int l, int r, vector<int> &s, vector<vector<int> > &dp) {
    if(dp[l][r] != -1) return dp[l][r];
    if(l == r) return dp[l][r] = 0;
    int ans = 2e9;
    for(int m = l; m < r; ++ m) 
        ans = min(ans, solve(l, m, s, dp) + solve(m + 1, r, s, dp));
    return dp[l][r] = ans + s[r] - s[l - 1];
}

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin>> n;
    vector<int> a(n + 1), s(n + 1);
    vector<vector<int> > dp(n + 1, vector<int> (n + 1, -1));
    for(int i = 1; i <= n; ++ i) 
        cin>> a[i];
    for(int i = 1; i <= n; ++ i) 
        s[i] = s[i - 1] + a[i];
    cout<< solve(1, n, s, dp) <<endl;
}
