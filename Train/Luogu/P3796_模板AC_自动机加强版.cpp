/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P3796 【模板】AC 自动机（加强版）
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P3796
| When:    2023-11-20 22:52:50
| 
| Memory:  128 MB
| Time:    3000 ms
*******************************/

/*
* ⣇⣿⠘⣿⣿⣿⡿⡿⣟⣟⢟⢟⢝⠵⡝⣿⡿⢂⣼⣿⣷⣌⠩⡫⡻⣝⠹⢿⣿⣷
* ⡆⣿⣆⠱⣝⡵⣝⢅⠙⣿⢕⢕⢕⢕⢝⣥⢒⠅⣿⣿⣿⡿⣳⣌⠪⡪⣡⢑⢝⣇
* ⡆⣿⣿⣦⠹⣳⣳⣕⢅⠈⢗⢕⢕⢕⢕⢕⢈⢆⠟⠋⠉⠁⠉⠉⠁⠈⠼⢐⢕⢽
* ⡗⢰⣶⣶⣦⣝⢝⢕⢕⠅⡆⢕⢕⢕⢕⢕⣴⠏⣠⡶⠛⡉⡉⡛⢶⣦⡀⠐⣕⢕
* ⡝⡄⢻⢟⣿⣿⣷⣕⣕⣅⣿⣔⣕⣵⣵⣿⣿⢠⣿⢠⣮⡈⣌⠨⠅⠹⣷⡀⢱⢕
* ⡝⡵⠟⠈⢀⣀⣀⡀⠉⢿⣿⣿⣿⣿⣿⣿⣿⣼⣿⢈⡋⠴⢿⡟⣡⡇⣿⡇⡀⢕
* ⡝⠁⣠⣾⠟⡉⡉⡉⠻⣦⣻⣿⣿⣿⣿⣿⣿⣿⣿⣧⠸⣿⣦⣥⣿⡇⡿⣰⢗⢄
* ⠁⢰⣿⡏⣴⣌⠈⣌⠡⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣬⣉⣉⣁⣄⢖⢕⢕⢕
* ⡀⢻⣿⡇⢙⠁⠴⢿⡟⣡⡆⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣵⣵⣿
* ⡻⣄⣻⣿⣌⠘⢿⣷⣥⣿⠇⣿⣿⣿⣿⣿⣿⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
* ⣷⢄⠻⣿⣟⠿⠦⠍⠉⣡⣾⣿⣿⣿⣿⣿⣿⢸⣿⣦⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟
* ⡕⡑⣑⣈⣻⢗⢟⢞⢝⣻⣿⣿⣿⣿⣿⣿⣿⠸⣿⠿⠃⣿⣿⣿⣿⣿⣿⡿⠁⣠
* ⡝⡵⡈⢟⢕⢕⢕⢕⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⣿⠿⠋⣀⣈⠙
* ⡝⡵⡕⡀⠑⠳⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⢉⡠⡲⡫⡪⡪⡣
*/

// #include <bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;
using Ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using PII = pair<int, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B){ return (ull)rng() % B; }

#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl
#define abs(a) ((a) >= 0 ? (a) : -(a))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mem(a, b) memset(a, b, sizeof(a))
// #define max(a, b) ((a) > (b) ? (a) : (b))
// #define min(a, b) ((a) < (b) ? (a) : (b))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define per(i, n, a) for (int i = n; i >= a; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&(-x))

const int N = 1000005; // 1e6 + 5
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 998244353;

// #define int long long

long long qmi(long long m, long long k, long long p = 9e18) {
    int res = 1 % p, t = m;
    while (k) {
        if (k&1) res = res * t % p;
        t = t * t % p, k >>= 1;
    }
    return res;
}
inline long long gcd(long long a, long long b) {return b ? gcd(b, a % b) : a;}
long long exgcd(long long a, long long b, long long &x, long long &y) {  
    if (!b) { x = 1; y = 0; return a; }  
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;  
    return d;
}

long long Sqrt(long long N) {
    __int128 sqrtN = sqrtl(N) - 1;
    while (sqrtN + 1 <= N / (sqrtN + 1))sqrtN++;
    return sqrtN;
}
// #define int long long

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
// #define int long long

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
