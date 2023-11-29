/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         https://www.luogu.com.cn/problem/solution/P3375
 * @DateTime    2023-11-19 03:21:47
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1000005; // 1e6 + 5

// #define int long long

// int nxt[N];

vector<int> kmp(string t) {
    vector<int> nxt(t.size() + 5);
    for(int i = 2, j = 0; i < t.size(); ++ i) {
        while(j && t[j + 1] != t[i]) j = nxt[j];  
        if(t[j + 1] == t[i]) ++ j;
        nxt[i] = j;
    }
    return nxt;
}

void solve();
signed main() {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // cout<< setiosflags(ios::fixed) << setprecision(10);
    // int _ = 1; cin>> _; while(_ --)
    string s, t;
    cin>> s >> t;
    s = " " + s;
    t = " " + t;
    auto nxt = kmp(t);

    for(int i = 1, j = 0; i < s.size(); ++ i) {
        while(j && t[j + 1] != s[i]) j = nxt[j];
        if(t[j + 1] == s[i]) ++ j;
        if(j == (int)t.size() - 1) {
            cout << i - ((int)t.size() - 1) + 1 <<endl;
            j = nxt[j];
        }
    }
    for(int i = 1; i < t.size(); ++ i) 
        cout << nxt[i] << " ";
    cout <<endl;
  return 0;
}

// #define int long long
void solve() {
    
}
