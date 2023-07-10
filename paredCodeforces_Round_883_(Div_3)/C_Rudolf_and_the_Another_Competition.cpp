/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C. Rudolf and the Another Competition
| Contest: Codeforces Round 883 (Div. 3)
| URL:     https://codeforces.com/contest/1846/problem/C
| When:    2023-07-09 12:30:26
|
| Memory:  256 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

#define int long long
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, m, h, res = 0;
    cin>> n >> m >> h;
    pair<int, int> r;
    std::vector<int> t;
    for(int i = 1; i <= n; i++) {
        t.clear();
        for(int j = 0; j < m; j++) {
            int k;
            cin>> k;
            t.push_back(k);
        }
        sort(t.begin(), t.end());
        int ttk = 0, sle = 0, te = 0;
        for(auto l:t) {
            ttk += te + l, te += l, sle ++;
            if(te > h)
                ttk -= te, sle --;
        }
        // cout<< sle << " " << ttk << " " << te <<endl;
        if(i == 1) r = {sle, ttk}, res ++;
        else if(sle > r.first || (sle == r.first && ttk < r.second)) res ++;
    }
    cout<< res <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
