/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C. Binary String Copying
| Contest: Educational Codeforces Round 152 (Rated for Div. 2)
| URL:     https://codeforces.com/contest/1849/problem/C
| When:    2023-07-28 00:46:21
| 
| Memory:  256 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, m;
    cin>> n >> m;
    string s;
    cin>> s;
    vector<int> nx1(n + 1, n), ls0(n + 1, -1);
    for(int i = n - 1; i >= 0; -- i) {
        if(s[i] == '1') nx1[i] = i;
        else nx1[i] = nx1[i + 1];
    }
    for(int i = 1; i <= n; ++ i) {
        if(s[i - 1] == '0') ls0[i] = i - 1;
        else ls0[i] = ls0[i - 1];
    }
    set<PII> st;
    while(m --) {
        int l, r;
        cin>> l >> r;
        l = nx1[l - 1];
        r = ls0[r];
        if(l > r) {
            l = r = -114514;
        }
        st.insert({l, r});
    }
    cout<< st.size() <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
