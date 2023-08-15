/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         https://www.acwing.com/problem/content/description/2/
 * @DateTime    2023-07-25 13:12:42
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
    vector<int> v(n + 5), w(n + 5);
    for(int i = 0; i < n; i++) {
        cin>> v[i + 1] >> w[i + 1];
    }


    // 逆推
    
    vector<int> dp(m + 5);

    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    cout<< dp[m] <<endl;

/*
    // 滚动数组
    
    vector<int> dp(m + 5), g(m + 5);
    
    // dp 储存第i - 1行, g 储存第i行

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j < v[i])
                g[j] = dp[j];
            else 
                g[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
        dp = g;
    } 
    cout<< dp[m] <<endl;
*/

/*   
    // 朴素暴力
    
    vector<vector<int> > dp(n + 5, vector<int> (m + 5));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j < v[i])
                dp[i][j] = dp[i - 1][j];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
        }
    }
    cout<< dp[n][m] <<endl;
*/
    return 0;
}
