/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Fine Logic
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57357/J
| When:    2023-07-24 13:55:05
| 
| Memory:  524288 MB
| Time:    4000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
int n, m, beg, ed, d[N];
bool st[N];

bool flag = 0, huan = 0;

vector<int> v[N], ans;
queue <int> q;
bool topsort(int x) {
    for(int i = x; i <= n; i++) {
        if(d[i] == 0) {
            ans.push_back(i);
            q.push(i);
        }
    }
    while(q.size()) {
        int x = q.front(); 
        q.pop();
        for(auto i:v[x]) {
            d[i]--;
            if(d[i] == 0) {
                ans.push_back(i);
                q.push(i);
            }
        }
    }
    return ans.size() == n;
}

void solve() {
    cin>> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;
        cin>> x >> y;
        v[x].push_back(y);
        d[y] ++;
    }
    if(topsort(1)) {
        cout<< 1 <<endl;
        for(auto i : ans) cout<< i << " ";
    }else {
        cout<< 2 <<endl;
        for(int i = 1; i <= n; i++) cout<< i << " "; cout<<endl;
        for(int i = n; i >= 1; i--) cout<< i << " "; cout<<endl;
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
