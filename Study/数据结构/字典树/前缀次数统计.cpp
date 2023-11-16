// 询问某字符串是几个字符串的前缀
#include <bits/stdc++.h>
using namespace std;
const int N = 1000005, char_size = 26; // 1e6 + 5

int cnt = 0;
struct Trie{
    int nxt[char_size];
    int tot;
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
            ++ trie[now].tot;
        }  
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
        cout << (!ans ? 0 : trie[now].tot) <<endl;
    }
}
