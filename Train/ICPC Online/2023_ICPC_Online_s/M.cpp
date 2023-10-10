#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long

struct C
{
    int a, b;
    double p;
    double ans;   
};

bool cmp (C a, C b) {
    return a.ans < b.ans;
}

void solve() {
    cout<< setiosflags(ios::fixed) << setprecision(17);
    int n;
    cin>> n;
    vector<C> node(n);
    vector<double> pre(n + 1);
    for(int i = 0; i < n; ++ i) {
        cin>> node[i].a >> node[i].b >> node[i].p;
        node[i].ans = node[i].a * 1.0 + 1.0 * node[i].b * node[i].p;
    }
    sort(node.begin(), node.end(), cmp);
    for(int i = 0; i < n; ++ i) {
        pre[i + 1] = pre[i] + node[i].ans;
    }
    double sum = 0;
    for(int i = 0; i <= n; ++ i) {
        sum += pre[i];
    }
    cout<< sum <<endl;

}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
