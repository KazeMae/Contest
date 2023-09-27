#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int N = 1e6 + 5;

struct UFS {
    vector<int> edge, node, p;

    UFS(int n) : edge(n + 5), node(n + 5), p(n + 5) {}

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
};

void solve() {
    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> ans;
    UFS st(n);
    for (int i = 1; i <= n; i++) st.p[i] = i, st.node[i] = 1;

    for (int i = 1; i <= m; i++) {
        int u, v; 
        cin >> u >> v;
        int x = st.find(u), y = st.find(v);
        if (x == y) st.edge[x]++;
        else st.p[y] = x, st.node[x] += st.node[y], st.edge[x] += (st.edge[y] + 1);
    }

    for (int i = 1; i <= n; i++) {
        st.p[i] = st.find(st.p[i]);
        int x = st.p[i];
        if (x == i) {
            sum += ((st.node[x] * (st.node[x] - 1) / 2) - st.edge[x]);
            ans.push_back(st.node[x]);
        }
    }

    sort(ans.begin(), ans.end());

    cout<< (sum != 0 ? sum : sum + ans[0] * ans[1]) <<endl;
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int _ = 1; cin>> _; while(_ --)
       solve();
}
