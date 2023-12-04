// AC自动机 应用
// 求模式串出现次数最多的次数, 求出现次数最多的模式串
#include <bits/stdc++.h>
using namespace std;

struct Zhenen {
    int pos, cnt;
    bool operator < (const Zhenen &t) const {
        if(cnt != t.cnt) 
            return cnt > t.cnt;
        else return pos < t.pos;
    }
};


struct autoAC {
    const int MX_N = 1000005; // 1e6 + 5

    struct Trie {
        int fail = 0; // 失配指针
        int vis[26]; // 子节点的位置
        int end = 0; // 标记几个单词以这个节点结尾
    };
    int tot = 0;
    vector <Trie> AC;

    autoAC() : AC(MX_N) {}

    // 建fail树
    void build(string s, int pos) {
        int l = s.size();
        int now = 0;
        for(int i = 0; i < l; ++ i) {
            int x = s[i] - 'a';
            if(!AC[now].vis[x])
                AC[now].vis[x] = ++ tot;
            now = AC[now].vis[x];
        }
        AC[now].end = pos;
    }
    // 求失配指针
    void fail() {
        queue<int> q;
        for(int i = 0; i < 26; ++ i) { // 处理第二层
            if(AC[0].vis[i]) {
                AC[AC[0].vis[i]].fail = 0; // 指向根节点
                q.push(AC[0].vis[i]);
            }
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i = 0; i < 26; ++ i) {
                if(AC[u].vis[i]) { // 子节点存在, 指向当前子节点的fail指针指向的节点的相同子节点
                    AC[AC[u].vis[i]].fail = AC[AC[u].fail].vis[i];
                    q.push(AC[u].vis[i]);
                }else AC[u].vis[i] = AC[AC[u].fail].vis[i]; // 不存在, 指向当前节点fail指针的这个子节点
            }
        }
    }
    // 匹配
    void query(string s, vector<Zhenen> &ans) {
        int l = s.size();
        int now = 0;
        for(int i = 0; i < l; ++ i) {
            int x = s[i] - 'a';
            now = AC[now].vis[x];
            for(int t = now; t && AC[t].end != -1; t = AC[t].fail) 
                ans[AC[t].end].cnt ++;
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

void solve() {
    int n;
    while(cin>> n) {
        if(n == 0) break;
        autoAC ac;
        vector<Zhenen> ans(n + 1);
        vector<string> s(n + 1);
        for(int i = 1; i <= n; ++ i) {
            cin>> s[i];
            ans[i].pos = i;
            ac.build(s[i], i);
        }
        ac.fail();
        cin>> s[0];
        ac.query(s[0], ans);
        sort(ans.begin() + 1, ans.end());
        cout << ans[1].cnt <<endl;
        for(int i = 1; i <= n; ++ i) 
            if(ans[i].cnt == ans[1].cnt)
                cout << s[ans[i].pos] <<endl;
            else break;
    }
} 
