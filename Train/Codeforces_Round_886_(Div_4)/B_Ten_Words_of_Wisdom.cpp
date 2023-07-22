/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: B. Ten Words of Wisdom
| Contest: Codeforces Round 886 (Div. 4)
| URL:     https://codeforces.com/contest/1850/problem/B
| When:    2023-07-21 22:40:19
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
    int n, ans = 0, ansmx = 0;
    cin>> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin>> x >> y;
        if(x <= 10) {
            if(ansmx < y) {
                ans = i;
                ansmx = y;
            }
        }
    }
    cout<< ans <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
