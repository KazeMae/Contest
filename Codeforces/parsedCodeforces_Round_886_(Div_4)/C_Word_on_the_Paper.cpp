/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C. Word on the Paper
| Contest: Codeforces Round 886 (Div. 4)
| URL:     https://codeforces.com/contest/1850/problem/C
| When:    2023-07-21 22:43:39
| 
| Memory:  256 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    string s[10], ans[10];
    for(int i = 0; i < 8; i++) {
        cin>> s[i];
    }
    for(int i = 0; i < 8; i ++) {
        for(int j = 0; j < 8; j++) {
            if(s[j][i] != '.')
                ans[i] += s[j][i];
        }
        if(ans[i].size() > 0) cout<< ans[i] <<endl;
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
