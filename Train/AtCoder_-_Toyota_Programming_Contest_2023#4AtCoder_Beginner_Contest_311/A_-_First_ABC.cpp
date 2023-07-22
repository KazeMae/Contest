/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A - First ABC
| Contest: AtCoder - Toyota Programming Contest 2023#4（AtCoder Beginner Contest 311）
| URL:     https://atcoder.jp/contests/abc311/tasks/abc311_a
| When:    2023-07-22 20:05:59
| 
| Memory:  1024 MB
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
    int n;
    string s;
    cin>> n >> s;
    bool a = 0, b = 0, c = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'A') a = 1;
        if(s[i] == 'B') b = 1;
        if(s[i] == 'C') c = 1;
        if(a && b && c) {
            cout<< i + 1 <<endl;
            return;
        }
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;/* cin>> t;*/ while(t --)
        solve();
}
