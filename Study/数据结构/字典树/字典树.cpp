// 查询是否在字典中存在
#include <bits/stdc++.h>
using namespace std;
const int N = 1000005, char_size = 26; // 1e6 + 5

int cnt = 0;
struct Trie{
    int nxt[char_size];
    bool isend;
} trie[N];

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q;
    cin>> n;
    string s;
    for(int i = 0, now = 0; i < n; ++ i, now = 0) {
        cin>> s;
        for(auto j : s) {
            int x = j - 'a';
            if(!trie[now].nxt[x]) trie[now].nxt[x] = ++ cnt;
            now = trie[now].nxt[x]; 
        }
        trie[now].isend = 1;
    }
    cin >> q;
    for(int i = 0, now = 0; i < q; ++ i, now = 0) {
        cin>> s;
        bool ans = true;
        for(auto j : s) {
            int x = j - 'a';
            if(!trie[now].nxt[x]) ans = false;
            else now = trie[now].nxt[x];
            if(!ans) break;
        }
        if(ans && !trie[now].isend) ans = false;
        cout << ans <<endl;
    }
}
