/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: B - Vacation Together
| Contest: AtCoder - Toyota Programming Contest 2023#4（AtCoder Beginner Contest 311）
| URL:     https://atcoder.jp/contests/abc311/tasks/abc311_b
| When:    2023-07-22 20:09:58
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
    int n, d;
    cin>> n >> d;
    vector<int> k(d);
    for(int i = 0; i < n; i++) {
        string s;
        cin>> s;
        for(int j = 0; j < d; j++) {
            if(s[j] == 'x') k[j] = 1;
        }
    }
    int cnt = 0, ans = 0;
    for(int i = 0; i < d; i++) {
        // cout<< k[i] << " ";
        if(k[i] == 0) cnt ++;
        else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    cout<< max(ans, cnt) <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;/* cin>> t;*/ while(t --)
        solve();
}
