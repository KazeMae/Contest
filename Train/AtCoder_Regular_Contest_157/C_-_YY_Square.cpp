/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C - YY Square
| Contest: AtCoder - AtCoder Regular Contest 157
| URL:     https://atcoder.jp/contests/arc157/tasks/arc157_c
| When:    2023-08-21 14:42:05
| 
| Memory:  1024 MB
| Time:    3000 ms
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

// #define int long long

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
ll myRand(ll B) { return (ull)rng() % B; }

#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl
#define abs(a) ((a) >= 0 ? (a) : -(a))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mem(a, b) memset(a, b, sizeof(a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define per(i, n, a) for (int i = n; i >= a; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) x&(-x)

const int N = 1000005; // 1e6 + 5
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 998244353;

long long qmi(long long m, long long k, long long p = 2e18) {
    int res = 1 % p, t = m;
    while (k) {
        if (k&1) res = res * t % p;
        t = t * t % p, k >>= 1;
    }
    return res;
}
inline long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {  
    if (!b) { x = 1; y = 0; return a; }  
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;  
    return d;
}

long long ans = 0, cnt = 0;

vector<vector<PII> > dist(2005, vector<PII> (2005));

void dfs(int x, int y, int n, int m) {
    // mo[x][y] ++;
    if(x == n && y == m) {
        // cout<< cnt << " " << mo[x][y] <<endl;
        ans += qmi(cnt, 2, MOD);
        ans %= MOD;
        return;
    }
    if(x + 1 <= n) {
        cnt += dist[x + 1][y].first;
        dfs(x + 1, y, n, m);
        cnt -= dist[x + 1][y].first;
    }
    if(y + 1 <= m) {
        cnt += dist[x][y + 1].second;
        dfs(x, y + 1, n, m);
        cnt -= dist[x][y + 1].second;
    }
}


void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n + 1);
    for(int i = 1; i <= n; ++ i) {
        cin>> s[i];
        s[i] = " " + s[i];
    }

    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j) {
            if(s[i][j] == 'Y'){
                int dx = i + 1, dy = j + 1;
                if(dx <= n) 
                    if(s[dx][j] == 'Y') dist[dx][j].first ++;
                if(dy <= m) 
                    if(s[i][dy] == 'Y') dist[i][dy].second ++;
            }
        }

    vector<vector<array<long long, 3>> > dp (2005, vector<array<long long, 3> > (2005));
    vector<vector<pair<int, int> > dpSn (2005, vector<pair<int, int> > (2005));

    dp[1][1][0] = 1;
    for(int i = 2; i <= 2 * n; ++ i) {
        for(int j = 1; j <= 2 * m; ++ j) {
            dp[i][j][0] = dp[i - 1][j - 1][0] + dp[i - 1][j][0];
        }
    }

    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= m; ++ j) {
            // cout<< i << " " << j << " " << n + m - i - j + 1 << " " << n - i + 1 << "  = " << dp[n + m - i - j + 1][n - i + 1][0] <<endl;
            if(i - 1 > 0) {
                dp[i][j][1] += dp[i - 1][j][1] + dist[i][j].first;
                dp[i][j][2] += dp[i - 1][j][2] + (dist[i][j].first * ((2 * dp[i - 1][j][1] + 1) * dp[n + m - i - j + 1][n - i + 1][0] % MOD)) % MOD;
                dp[i][j][2] %= MOD;
            }
            if(j - 1 > 0) {
                dp[i][j][1] += dp[i][j - 1][1] + dist[i][j].second;
                dp[i][j][2] += dp[i][j - 1][2] + (dist[i][j].second * ((2 * dp[i][j - 1][1] + 1) * dp[n + m - i - j + 1][n - i + 1][0] % MOD)) % MOD;
                dp[i][j][2] %= MOD;
            }
        }
    }

    cout<< dp[n][m][2] % MOD <<endl;


    cout << endl <<  "-> debug :" << endl;
    
    for(int i = 1;  i <= n; ++ i) {
        for(int j = 1; j <=m; ++ j) {
            cout<< dist[i][j].first << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 1;  i <= n; ++ i) {
        for(int j = 1; j <=m; ++ j) {
            cout<< dist[i][j].second << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 1;  i <= 2 * n; ++ i) {
        for(int j = 1; j <= 2 * m; ++ j) {
            cout<< dp[i][j][0] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 1;  i <= n; ++ i) {
        for(int j = 1; j <=m; ++ j) {
            cout<< dp[i][j][1] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 1;  i <= n; ++ i) {
        for(int j = 1; j <=m; ++ j) {
            cout<< dp[i][j][2] << " ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout << ans <<endl;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
