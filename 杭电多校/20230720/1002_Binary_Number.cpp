/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime 2023-07-20 20:32:22
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1000005; // 1e6 + 5

void solve() {
    int n, k, cnt = 0;
    string r, s;
    cin >> n >> k >> r;
    s = r;
    if (n == 1)
    {
        if (k & 1) cout<< (s[0] == '0' ? 1 : 0) <<endl;
        else cout<< (s[0] == '1' ? 1 : 0) <<endl;
        return;
    }
    if (s.find('0') == -1)
    {
        if (k == 1) s.back() = '0';
        cout << s <<endl;
        return;
    }
    for (int i = 0; i < s.size(); i ++)
    {
        if (r[i] == '0' && r[i - 1] == '1') cnt ++;
        if (cnt <= k) s[i] = '1';
    }
    cout << s <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
