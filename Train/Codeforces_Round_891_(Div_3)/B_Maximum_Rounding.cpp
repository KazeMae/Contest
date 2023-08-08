/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: B. Maximum Rounding
| Contest: Codeforces Round 891 (Div. 3)
| URL:     https://codeforces.com/contest/1857/problem/B
| When:    2023-08-07 22:44:27
| 
| Memory:  256 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
const int MOD = 998244353;
 
void solve() {
    string s;
    cin>> s;
    reverse(s.begin(), s.end());
    s += "0";
    int n = s.size();
    for(int i = 0, mk = 0; i < n; ++ i) {
        // cout<< i << " " << n + 1 <<endl;
        if(s[i] >= '5') {
            int k = i - 1;
            while(k >= mk) s[k --] = '0';
            mk = max(0, i - 1);
            s[i ++] = '0';
            while(i < n) {
                if(s[i] == '9') s[i ++] = '0';
                else {
                    s[i] ++;
                    -- i;
                    break;
                }
            }
        }
    }
    reverse(s.begin(), s.end());
    if(s[0] != '0') cout<< s[0];
    for(int i = 1; i < n; i++) cout<< s[i];
    cout<< endl;
}
signed main () {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
