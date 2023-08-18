/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: We are the Lights
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57358/L
| When:    2023-07-28 13:12:01
| 
| Memory:  1048576 MB
| Time:    4000 ms
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
    vector<PII> a(n);
    for(int i = 0; i < n; ++ i) {
        cin>> a[i].first, a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    int l = 0, r = n - 1;
    while(n -- > 1) {
        int ll = l, rr = r;
        while(ll < rr) {
            int mid = ll + rr >> 1;
            if(a[mid].first * 2 > a[l].first + a[r].first) rr = mid;
            else ll = mid + 1;
        }
        if(r - ll + 1 <= ll - l) r --;
        else l ++;
    }
    cout << a[l].second<< endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
        solve();
}
