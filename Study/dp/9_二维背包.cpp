/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         https://www.acwing.com/problem/content/8/
 * @DateTime    2023-07-26 01:24:19
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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n + 5), w(n + 5), t(n + 5);
    for(int i = 0; i < n; i++) {
        cin>> v[i + 1] >> t[i + 1] >> w[i + 1];
    } 

    // 压缩维度

    vector<vector<int> >  dp(m + 5, vector<int> (k + 5, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= v[i]; j--) {
            for(int l = k; l >= t[i]; l--) {
                dp[j][l] = max(dp[j][l], dp[j - v[i]][l - t[i]] + w[i]);
            }
        }
    } 
    cout<< dp[m][k] <<endl;

/*
    // 朴素背包

    vector<vector<vector<int> > > dp(n + 5, vector<vector<int> > (m + 5, vector<int> (k + 5, 0)));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int l = 1; l <= k; l++) {
                if(j >= v[i] && l >= t[i]) 
                    dp[i][j][l] = max(dp[i - 1][j][l], dp[i - 1][j - v[i]][l - t[i]] + w[i]);
                else 
                    dp[i][j][l] = dp[i - 1][j][l];
            }
        }
    } 

    cout<< dp[n][m][k] <<endl;
 */   
}
