/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @Url https://www.acwing.com/problem/content/897
 * @DateTime 2023-07-21 20:32:15
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
    vector<int> a(n), dp(n);
    for(int i = 0; i < n; i++)
        cin>> a[i];

    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout<< *max_element(dp.begin(), dp.end());
}
