// 字符串排序
#include <bits/stdc++.h>
using namespace std;
const int N = 1000005, char_size = 26; // 1e6 + 5

int cnt = 0;
struct Trie{
    int nxt[char_size];
    bool isend;
} trie[N];

int ans[N];
inline void dfs(int now, int dep) {
    if(trie[now].isend) {
        for(int i = 0; i < dep; ++ i) 
            cout<< (char)(ans[i] + 'a');
        cout <<endl; 
    }
    for(int i = 0; i < char_size; ++ i) {
        if(trie[now].nxt[i]) {
            ans[dep] = i;
            dfs(trie[now].nxt[i], dep + 1);
        }
    }
}

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin>> n;
    string s;
    for(int i = 0, now = 0; i < n; ++ i, now = 0) {
        cin>> s;
        for(auto j : s) {
            int x = j - 'a';
            if(!trie[now].nxt[x]) trie[now].nxt[x] = ++ cnt;
            now = trie[now].nxt[x]; 
        }
        trie[now].isend = true;
    }
    dfs(0, 0);
}
