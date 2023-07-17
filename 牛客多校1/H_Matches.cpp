/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime 2023-07-17 14:27:52
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

#define int long long
const int N = 1000005; // 1e6 + 5

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, res = 0, mxi = 0, mx = 0;
    cin>> n;
    vector<int> a(n), b(n);
    vector<pair<int, int> > ans(n);
    for(int i = 0; i < n; i ++) {
        cin>> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin>> b[i];
        ans[i].first = abs(a[i] - b[i]), ans[i].second = i;
        res += ans[i].first;
        if(ans[i].first > mx) {
            mx = ans[i].first;
            mxi = i;
        }
    }
    res -= ans[mxi].first;
    int anns = res + ans[mxi].first;
    for(int i = 0; i < n; i++) {
        if(i == mxi) continue;
        anns = min(anns, res - ans[i].first + abs(a[mxi] - b[i]) + abs(b[mxi] - a[i]));
    }
    cout<< anns <<endl;
}
