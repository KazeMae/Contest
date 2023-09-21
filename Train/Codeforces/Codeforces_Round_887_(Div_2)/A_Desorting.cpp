/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Desorting
| Contest: Codeforces Round 887 (Div. 2)
| URL:     https://codeforces.com/contest/1853/problem/A
| When:    2023-07-23 22:36:44
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
    int n;
    cin>> n;
    vector<int> a(N);
    int ans = 2e9;
    for(int i = 0; i < n; i++) {
        cin>> a[i];
        if(i != 0 && a[i - 1] > a[i]) ans = 0;
    }
    if(ans != 0) {
        for(int i = 1; i < n; i++) {
            if(a[i] >= a[i - 1]) ans = min((a[i] - a[i - 1] + 1) / 2 + (a[i] - a[i - 1] + 1) % 2, ans);
        }
    }
    cout<< ans <<endl;

}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
