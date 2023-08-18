/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Ama no Jaku
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57357/D
| When:    2023-07-24 15:44:40
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

bool check(string x, string y) {
    for(int i = 0; i < x.size() ; i++) {
        if(!(x[i] == '1' && y[x.size() - i - 1] == '0' || x[i] == '0' && y[x.size() - i - 1] == '1'))
            return false;
    }
    return true;
}

void solve() {
    int n, r1 = 0, l1 = 0;
    cin>> n;
    vector<string> s(2005);
    string sf;
    for(int i = 0; i < n; i ++) {
        cin>> s[i];
    }
    sf = s[0];
    if(n == 1) {
        cout<< 0;
        return;
    }
    for(int i = 0; i < n; i ++) {
        s[0][i] == '1' ? sf[i] = '0', r1 ++ : sf[i] = '1';
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == s[0]);
        else if(s[i] == sf) l1 ++;
        else {
            cout<< -1;
            return;
        }
    }
    // cout<< ans <<endl;
    cout<< min({l1 + r1, n - l1 + n - r1, l1 + n - r1, r1 + n - l1});

}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
