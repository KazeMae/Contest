/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         
 * @DateTime    
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5
int n, m, beg, ed;
bool st[N];
vector<int> v[N], ans;
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


signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n = 2e5;
    cout<< n <<endl;
    for(int i = 0; i < n; i++) {
        cout<< 1 <<endl;
        cout<< 1 <<endl;
    }
}
