// 最长公共前缀
#include <bits/stdc++.h>
using namespace std;
const int N = 1000005, char_size = 26; // 1e6 + 5

int cnt = 0, fa[N][21], idx[N], d[N];
struct Trie{
    int nxt[char_size];
} trie[N];

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin>> n;
    string s;
    for(int i = 1, now = 0; i <= n; ++ i, now = 0) {
        cin>> s;
        for(auto j : s) {
            int x = j - 'a';
            if(!trie[now].nxt[x]) {
                trie[now].nxt[x] = ++ cnt;
                fa[cnt][0] = now;
                d[cnt] = d[now] + 1;
            }
            now = trie[now].nxt[x]; 
        }
        idx[i] = now;
    }
    for(int i = 1; i <= 20; ++ i) 
        for(int j = 1; j <= cnt; ++ j) 
            if(fa[j][i - 1]) 
                fa[j][i] = fa[fa[j][i - 1]][i - 1];
    cin>> m;
    for(int i = 0; i < m; ++ i) {
        int x, y;
        cin>> x >> y;
        x = idx[x], y = idx[y];
        if(d[x] < d[y]) swap(x, y);
        int z = d[x] - d[y];
        for(int j = 0; j < 20 && z; ++ j, z /= 2) 
            if(z & 1)
                x = fa[x][j];

        if(x == y) {
            cout<< d[x] <<endl;
            continue;
        }
        for(int j = 20; j >= 0; -- j) {
            if(fa[x][j] != fa[y][j]) 
                x = fa[x][j], y = fa[y][j];
        }
        // cout << x << " " << y << " " << fa[x][0] <<endl;
        cout<< d[fa[x][0]] <<endl;
    }

}
