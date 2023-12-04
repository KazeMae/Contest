#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5

struct autoAC {
    const int MX_N = 1000005; // 1e6 + 5

    struct Trie {
        int fail; // 失配指针
        int vis[26]; // 子节点的位置
        int end; // 标记几个单词以这个节点结尾
    };
    int tot = 0;
    vector <Trie> AC;

    autoAC() : AC(MX_N) {}

    // 建fail树
    void build(string s) {
        int l = s.size();
        int now = 0;
        for(int i = 0; i < l; ++ i) {
            int x = s[i] - 'a';
            if(!AC[now].vis[x])
                AC[now].vis[x] = ++ tot;
            now = AC[now].vis[x];
        }
        ++ AC[now].end;
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
    int query(string s) {
        int l = s.size();
        int now = 0, ans = 0;
        for(int i = 0; i < l; ++ i) {
            int x = s[i] - 'a';
            now = AC[now].vis[x];
            for(int t = now; t && AC[t].end != -1; t = AC[t].fail) 
                ans += AC[t].end, AC[t].end = -1;
        }
        return ans;
    }
};

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    string s;
    cin>> n;
    autoAC ac;
    for(int i = 0; i < n; ++ i) {
        cin>> s;
        ac.build(s);
    }
    ac.fail();
    cin>> s;
    cout << ac.query(s) <<endl;
}
