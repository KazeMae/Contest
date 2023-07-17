/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime 2023-07-17 14:45:08
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// #define int long long
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
int n, m, k;
int dis[N];
bool st[N];
vector<int> e[N];

int djgsr() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > heap;
    heap.push({0, 1});

    while(!heap.empty()) {
        auto t = heap.top();
        heap.pop();

        int v = t.second, ds = t.first;
        if(st[v]) continue;
        st[v] = true;

        for(auto i:e[v]) {
            if(dis[i] > ds + 1) {
                dis[i] = ds + 1;
                heap.push({dis[i], i});
            }
        }

    }
    if(dis[n] == 0x3f3f3f3f) return -1;
    return dis[n];
}


signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>> n >> m >> k;
    for(int i = 0; i < n; i++) {
        int u, v;
        cin>> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    cout<< djgsr() <<endl;


}
