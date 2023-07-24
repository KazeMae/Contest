/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C - Find it!
| Contest: AtCoder - Toyota Programming Contest 2023#4（AtCoder Beginner Contest 311）
| URL:     https://atcoder.jp/contests/abc311/tasks/abc311_c
| When:    2023-07-22 20:22:15
| 
| Memory:  1024 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
int n, a, beg = 0, ed = 0;
vector<int> v[N], st(N), k;
vector<int> ans;
bool flag = 0, huan = 0;
void dsf(int x) {
    if(st[x]) {
        ed = x;
        huan = 1;
        return;
    }
    st[x] = 1;
    for(auto i:v[x]) {
        dsf(i);
    }
    st[x] = 0;
}
void dfs(int x) {
    if(st[x]) return;
    st[x] = 1;
    ans.push_back(x);
    for(auto i:v[x]) {
        if(i == beg) {
            flag = 1;
            return;
        }else dfs(i);
    }
    st[x] = 0;
}

void solve() {
    cin>> n;
    for(int i = 1; i <= n; i++) {
        cin>> a;
        v[i].push_back(a);
        k.push_back(a);
    }
    dsf(1);
    beg = ed;
    dfs(ed);
    cout<< ans.size() <<endl;
    for(auto i:ans) {
        cout<< i << " ";
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; /*cin>> t;*/ while(t --)
        solve();
}
