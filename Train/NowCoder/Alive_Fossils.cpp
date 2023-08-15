/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Alive Fossils
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57362/A
| When:    2023-08-11 12:03:33
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
const int MOD = 998244353;
 
void solve() {
    int n, c;
    string na;
    map<string, int> mp;
    cin>> n;
    for(int i = 0; i < n; ++ i) {
        cin>> c;
        for(int j = 0; j < c; ++ j) {
            cin>> na;
            mp[na] ++;
        }
            
    }
    vector<string> ans;
    for(auto i:mp) {
        if(i.second == n) ans.push_back(i.first);
    }
    cout<< ans.size() <<endl;
    for(auto i:ans) cout<< i <<endl;

}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
