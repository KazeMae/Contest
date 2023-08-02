/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Escalator Conversations
| Contest: Codeforces Round 888 (Div. 3)
| URL:     https://codeforces.com/contest/1851/problem/A
| When:    2023-07-25 22:52:18
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
    int n, m, k, h, ans = 0;
    cin>> n >> m >> k >> h;
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin>> a[i];
    }
    for(int i = 0; i < n; i++) {
        if(a[i] <= h) {
            int mm = m - 1;
            while (mm -- && a[i] <= h) {
                if(abs(a[i] - h) == k) {
                    ans ++; break;
                }else a[i] += k;
            }
        }else {
            int mm = m - 1;
            while (mm -- && a[i] >= h) {
                if(abs(a[i] - h) == k) {
                    ans ++; break;
                }else a[i] -= k;
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
