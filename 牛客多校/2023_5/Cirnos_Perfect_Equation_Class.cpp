/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Cirno's Perfect Equation Class
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57359/D
| When:    2023-07-31 12:10:24
| 
| Memory:  524288 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    sort(res.begin(), res.end());
    return res;
}

void solve() {
    int k, c, n, ans = 0;
    cin>> k >> c >> n;
    auto C = get_divisors(c);
    set<PII> st;
    for(int gd = C.size() - 1; gd >= 0; -- gd) {
        int ka = c - C[gd];
        if(ka / k >= n && ka % k == 0 && __gcd((ka / k), C[gd]) >= n) st.insert({(ka / k), C[gd]});
    }
    cout<< st.size() <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
