/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C. Particles
| Contest: Codeforces Round  884 (Div. 1 + Div. 2)
| URL:     https://codeforces.com/contest/1844/problem/C
| When:    2023-07-11 23:47:37
| 
| Memory:  256 MB
| Time:    1000 ms
*******************************/
/**
 * WA
 */
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
int a[N];
void solve() {
    int n, x, sum = 0;
    cin>> n;
    for(int i = 0; i < n; i++) {
        cin>> a[i];
    }
    if(n == 1) {
        cout<< a[0] <<endl;
        return;
    }
    if(n == 2) {
        cout<< max(a[0], a[1]) <<endl;
        return;
    }
    if(a[0] > 0) sum = a[0];
    for(int i = 1; i < n - 1; i++) {
        if(a[i] <= a[i + 1]) sum += a[++ i];
        else if(sum < a[i]) sum = a[i];
        // cout<< sum << " *\n";
    }
    cout<< sum << endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
/**
 * 9 4 -4 8 2 -4 7
 * 9 12 2 -4 7
 * 9 12 9
 * 18
 */
