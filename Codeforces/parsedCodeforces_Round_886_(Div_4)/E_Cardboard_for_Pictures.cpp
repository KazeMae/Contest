/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: E. Cardboard for Pictures
| Contest: Codeforces Round 886 (Div. 4)
| URL:     https://codeforces.com/contest/1850/problem/E
| When:    2023-07-21 23:07:25
| 
| Memory:  256 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
int n, c;
vector<int> s(N);

bool check(int mid) {
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (mid + mid + s[i]) * (mid + mid + s[i]);
        if(sum > 1e18) return true;
    }
    return sum >= c;
}
void solve() {
    cin>> n >> c;
    for(int i = 0; i < n; i ++) {
        cin>> s[i];
    }
    int l = 0, r = 1e9;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout<< l <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
