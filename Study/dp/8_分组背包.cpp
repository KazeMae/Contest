/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         https://www.acwing.com/problem/content/9/
 * @DateTime    2023-07-25 16:36:31
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
    int n, m, a, x, y, idx = 1, idk = 1;
    cin>> n >> m;
    vector<vector<PII> > v(n + 5, vector<PII> (m + 5));
    for(int i = 1; i <= n; i++) {
        cin>> a;
        for(int j = 0; j < a; j++) {
            cin>> x >> y;
            v[i].push_back({x, y});
        }
    }

    // 优化空间复杂度

    vector<int> dp(m + 5);

    for(int i = 1; i <= n; i++) {
        for(int j = m; j; j--) {
            for(auto k:v[i]) {
                if(j >= k.first) {
                    dp[j] = max(dp[j], dp[j - k.first] + k.second);
                }
            }
        }
    }

    cout<< dp[m] <<endl;


/*
    // 朴素暴力
    
    vector<vector<int> > dp(n + 5, vector<int> (m + 5));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            for(auto k:v[i]) {
                if(j >= k.first) 
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k.first] + k.second);
            }
        }
    }
    cout << dp[n][m] <<endl;

*/}
