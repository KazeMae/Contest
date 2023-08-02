/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: 替换大师
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/62332/K
| When:    2023-07-26 15:16:15
| 
| Memory:  524288 MB
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
    bool l = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') l = 1;
        else if(l && s[i] == ',') s[i] = '.';
        else if(s[i] == ')') l = 0;
        cout<< s[i];
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
