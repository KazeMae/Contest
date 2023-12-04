// AC自动机_拓扑排序优化建图
// 输出包含 n 行，其中第 i 行包含一个非负整数表示 T_i 在 S 中出现的次数。
#include <bits/stdc++.h>
using namespace std;

struct autoAC {
    const int MX_N = 1000005; // 1e6 + 5

    struct Trie {
        int fail = 0; // 失配指针
        int son[26]; // 子节点的位置
        int end = 0; // 标记几个单词以这个节点结尾
        int ans = 0;
    };
    int tot = 1;
    vector <Trie> AC;
    vector<int> vis, rev, indeg;

    autoAC() : AC(MX_N), vis(MX_N, 0), rev(MX_N), indeg(MX_N) {}

    // 建fail树
    void build(string s, int pos) {
        int l = s.size();
        int now = 1;
        for(int i = 0; i < l; ++ i) {
            int x = s[i] - 'a';
            if(!AC[now].son[x]) AC[now].son[x] = ++ tot;
            now = AC[now].son[x];
        }
        if(!AC[now].end) AC[now].end = pos;
        rev[pos] = AC[now].end;
    }
    // 求失配指针
    void fail() {
        queue<int> q;
        for(int i = 0; i < 26; ++ i) // 处理第二层
            AC[0].son[i] = 1;
        q.push(1);
        while(!q.empty()) {
            int u = q.front();
            int Fail = AC[u].fail;
            q.pop();
            for(int i = 0; i < 26; ++ i) {
                int v = AC[u].son[i];
                if(!v) { // 子节点存在
                    AC[u].son[i] = AC[Fail].son[i];
                    continue;
                }
                AC[v].fail = AC[Fail].son[i];
                indeg[AC[v].fail] ++;
                q.push(v);
            }
        }
    }

    void topu() {
        queue<int> q;
        for(int i = 1; i <= tot; ++ i)
            if(indeg[i] == 0) q.push(i);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            vis[AC[u].end] = AC[u].ans;
            int v = AC[u].fail;
            indeg[v] --;
            AC[v].ans += AC[u].ans;
            if(indeg[v] == 0) q.push(v);
        }
    }

    // 匹配
    void query(string s) {
        int u = 1, n = s.size();
        for(int i = 0; i < n; ++ i) {
            int x = s[i] - 'a';
            u = AC[u].son[x], AC[u].ans ++;
        }
    }
};


void solve();
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // cout<< setiosflags(ios::fixed) << setprecision(10);
    // int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
// #define int long long

void solve() {
    int n, mx = 0;
    string s;
    cin>> n;
    autoAC ac;
    for(int i = 1; i <= n; ++ i) {
        cin>> s;
        ac.build(s, i);
    }
    ac.fail();
    cin>> s;
    ac.query(s);
    ac.topu();
    for(int i = 1; i <= n; ++ i) 
        cout << ac.vis[ac.rev[i]] <<endl;
} 
