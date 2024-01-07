#include <bits/stdc++.h>

using namespace std;

using i32 = int32_t;
using vi = vector<int>;
using pii = pair<int, int>;
const int inf = 2e9+5;


i32 main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edge(m);
    vector<vector<pii>> e(n + 1);
    for (auto &[u, v, w]: edge) {
        cin >> u >> v >> w;
        e[u].emplace_back(v, w);
        e[v].emplace_back(u, w);
    }
    auto dij = [e, n](int x) {
        priority_queue<pii, vector<pii>, greater<pii>> q;
        vi dis(n + 1, inf);
        vector<bool> vis(n + 1);
        dis[x] = 0, q.emplace(0, x);
        while (not q.empty()) {
            auto [d, u] = q.top();
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            for (auto [v, w]: e[u]) {
                if (vis[v] or max(d, w) >= dis[v]) continue;
                dis[v] = max(d, w), q.emplace(dis[v], v);
            }
        }
        return dis;
    };
    auto d1 = dij(1), dn = dij(n);
    int res = inf;
    for (auto [u, v, w]: edge) {
        if (max(d1[u], dn[v]) <= w)
            res = min(res, w + max(d1[u], dn[v]));
        if (max(dn[u], d1[v]) <= w)
            res = min(res, w + max(dn[u], d1[v]));
    }
    cout << res << "\n";
    return 0;
}
