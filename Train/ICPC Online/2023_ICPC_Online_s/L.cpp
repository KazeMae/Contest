/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         
 * @DateTime    
 */
// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

using ull = unsigned long long;

#define endl '\n'

const int N = 10005; // 1e4 + 5
const int P = 131, PP = 196613;

unsigned long long h[N], hh[N], p[N], pp[N];

ull get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}
ull gett(int l, int r) {
    return hh[r] - hh[l - 1] * pp[r - l + 1];
}

void solve() {
    string s;
    cin>> s;
    int cnt = 0, n = s.size();
    for(int i = 1; i <= n; ++ i) 
        h[i] = h[i - 1] * P + s[i - 1], hh[i] = hh[i - 1] * PP + s[i - 1];

    for(int i = 0; i < n; ++ i) {
        int d = 0;
        bool hw = 1;
        while(i - d + 1 >= 1 && i + d + 2 <= n) {
            if(hw && get(i - d + 1, i - d + 1) == get(i + d + 2, i + d + 2) 
                && gett(i - d + 1, i - d + 1) == gett(i + d + 2, i + d + 2)
            ) cnt ++;
            else hw = 0;
            if(!hw 
                && get(i - d + 1, i + 1) == get(i + 2, i + d + 2) 
                && gett(i - d + 1, i + 1) == gett(i + 2, i + d + 2)
            ) 
                cnt ++;
            ++ d;
        }
    }
    cout<< cnt <<endl;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    p[0] = 1, pp[0] = 1;
    for(int i = 1; i < N; ++ i) p[i] = p[i - 1] * P, pp[i] = pp[i - 1] * PP;
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
