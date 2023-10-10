/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: E. Speedrun
| Contest: Pinely Round 2 (Div. 1 + Div. 2)
| URL:     https://codeforces.com/contest/1863/problem/E
| When:    2023-08-31 01:09:50
| 
| Memory:  256 MB
| Time:    2000 ms
*******************************/

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

vector<int> e[N], ue[N];
vector<int> w(N);
int n, m, k;
int dist[N];        // 存储每个点到1号点的最短距离
bool st[N];     // 存储每个点是否在队列中


int spfa()
{
    memset(dist, 0, sizeof dist);
    dist[0] = 0;

    queue<int> q;
    q.push(0);
    st[0] = true;

    for(auto i:e[0]) cout<< i << " "; cout << endl;
    while (q.size()) {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (auto i:e[t]) {
            int j = i;
            if (dist[j] < (w[j] > w[i] ? (dist[t] / 24 + 1) * 24 + w[j] : dist[t] + w[j])) {
                dist[j] = dist[t] + w[i];
                if (!st[j])     // 如果队列中已存在j，则不需要将j重复插入
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

void solve() {
    for(int i = 1; i <= n; ++ i) 
        cin>> w[i];

    for(int i = 0; i < m; ++ i) {
        int u, v;
        cin>> u >> v;
        e[u].push_back(v);
        ue[v].push_back(u);
    }

    for(int i = 1; i <= n; ++ i) {
        if(ue[i].empty()) e[0].push_back(i);
        sort(e[i].begin(), e[i].end());
    }
    sort(e[0].begin(), e[0].end());
    cout<< spfa() <<endl;

}
signed main() {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
