/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime 2023-07-20 18:57:25
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1000005; // 1e6 + 5

void solve() {
    string s;
    cin>> s;
    int n = s.size(), k = 0, len = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == s[i - 1]) len ++;
        else k++, len++;
    }
    cout<< len - k <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
