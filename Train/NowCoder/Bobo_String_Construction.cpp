/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Bobo String Construction
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57358/A
| When:    2023-07-28 15:03:09
| 
| Memory:  1048576 MB
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
    int n, t0 = 0, t1 = 0;
    string s, f0, f1;
    cin>> n >> s;
    int len = s.size();
    string ans0(n, '1'), ans1(n, '0');
    f0 = s + ans0 + s, f1 = s + ans1 + s;
    // cout<< f0 << endl << f1 << endl;
    for(int i = 0; i < f0.size(); ++ i) {
        // cout<< i << " *" <<endl;
        if(f0.find(s, i) != -1) t0 ++, i = f0.find(s, i);
        else break;
        // cout<< i <<endl;
    }
    for(int i = 0; i < f1.size(); ++ i) {
        // cout<< i << " *" <<endl;
        if(f1.find(s, i) != -1) t1 ++, i = f1.find(s, i);
        else break;
        // cout<< i <<endl;
    }
    // cout<< t0 << " " << t1 <<endl;
    if(t0 <= 2) cout<< ans0 <<endl;
    else cout<< ans1 <<endl;
}
signed main () {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
