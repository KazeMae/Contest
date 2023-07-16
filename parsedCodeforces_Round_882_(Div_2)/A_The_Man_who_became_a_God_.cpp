/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. The Man who became a God 
| Contest: Codeforces Round 882 (Div. 2)
| URL:     https://codeforces.com/contest/1847/problem/A
| When:    2023-07-13 23:13:31
| 
| Memory:  256 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
int a[N];
void solve() {
    int n, k, sum = 0;
    cin>> n >> k;
    for(int i = 0; i < n; i++) {
        cin>> a[i];
    }
    vector<int> v;
    for(int i = 1; i < n; i++) {
        v.push_back(abs(a[i] - a[i - 1]));
        sum += v.back();
    }
    sort(v.begin(), v.end());
    for(int i = 1; i < k; i++) {
        sum -= v.back();
        v.pop_back();
    }
    cout<< sum <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
