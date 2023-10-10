/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: B. Parity Sort
| Contest: Codeforces Round 888 (Div. 3)
| URL:     https://codeforces.com/contest/1851/problem/B
| When:    2023-07-25 22:51:49
| 
| Memory:  256 MB
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
    cin>> n;
    vector<int> a(n), b;
    for(int i = 0; i < n; i++) {
        cin>> a[i];
    }
    b = a;
    sort(b.begin(), b.end());
    bool flag = 1;
    for(int i = 0; i < n; i++) {
        if(a[i] % 2 != b[i] % 2) {
            flag = 0;
            break;
        }
    }
    cout<< (flag ? "YES" : "NO") <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
