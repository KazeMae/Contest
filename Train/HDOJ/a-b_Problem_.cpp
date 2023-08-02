/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: a-b Problem 
| Contest: HDOJ
| URL:     https://acm.hdu.edu.cn/contest/problem?cid=1097&pid=1012
| When:    2023-07-27 15:55:53
| 
| Memory:  65536 MB
| Time:    3000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, k = 0;
    ll aa = 0, ab = 0;
    cin>> n;
    vector<PII> a, b;
    vector<bool> st(n, 0);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin>> x >> y;
        a.push_back({x, i});
        b.push_back({y, i});
    }
    int ai = n - 1, bi = n - 1;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while(k < n) {
        for(ai; ai >= 0; -- ai) {
            if(st[a[ai].second] == 0) {
                aa += a[ai].first;
                st[a[ai].second] = 1;
                k ++;
                break;
            }
        }
        for(bi; bi >= 0; -- bi) {
            if(st[b[bi].second] == 0) {
                ab += b[bi].first;
                st[b[bi].second] = 1;
                k ++;
                break;
            }
        }
    }
    cout<< aa - ab <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
