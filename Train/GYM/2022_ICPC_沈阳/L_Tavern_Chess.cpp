/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: L. Tavern Chess
| Contest: Codeforces - The 2022 ICPC Asia Shenyang Regional Contest (The 1st Universal Cup, Stage 1: Shenyang)
| URL:     https://codeforces.com/gym/104160/problem/L
| When:    2023-12-06 17:37:33
| 
| Memory:  512 MB
| Time:    4000 ms
*******************************/

/********************************************
|⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠛⠛⠛⠛⠛⠿⣿⣿⣿⣿⣿⣷⠀⣿⣿⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠉⠀⠀⣠⣤⣤⣤⣤⣤⣤⣤⣀⠀⠉⠛⠿⠈⣦⠙⣿⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⣿⣿⣿⠟⠀⢀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⠀⣼⣿⣦⠙⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⠿⠛⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⣿⣿⣿⠀⠻⣿⣿⣿⣿⣿
|⣿⡟⠀⠀⠤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⣿⣿⣿⠆⠀⠀⠙⣿⣿⣿
|⣿⣆⠀⠀⠀⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠿⢿⠿⠀⠀⠀⠀ ⣿⣿⣿
|⣿⣿⣦⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣀⣤⣆⠀⢠⣿⣿⣿⣿
|⣿⣿⠋⠀⣿⣿⣿⣿⠋⠀⠈⢿⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣿⠉⠀⠈⣿⣿⣿⣿⡆⠈⣿⣿⣿⣿
|⣿⣿⠀⠸⠿⠿⣿⣿⠀⠀⠀⣸⣿⣿⡁⠀⠀⠀⠀⢙⣿⣿⣧⠀⠀⠀ ⢠⣿⡿⠿⠿ ⢹⣿⣿⣿
|⣟⠀⠀⠀⣀⠀⠀⠀⢙⣶⣾⣿⣿⣿⣿⣶⡄⢀⣴⣿⣿⣿⣿⣷⣶⡶⠁⠀⢀⠀⣀⠀⠀ ⢙⣿⣿
|⣿⠀⠻⠿⠛⠛⠛⠷⢾⣿⣿⣿⣿⣿⣿⣿⠇⠙⣿⣿⣿⣿⣿⣿⣿⣿⠒⠛⠛⠻⠿⢿⠀⢿⣿⣿         
|⠟⠀⢀⢀⣤⣶⣶⣦⣾⣿⣿⣿⣿⣿⣿⢀⣶⣶⣀⠙⣿⣿⣿⣿⣿⣿⣦⣤⣶⣦⣄⠀⠀⠘⣿⣿
|⣷⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⣶⣿⣿
|⣿⣆⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⢠⣿⣿⣿
|⣿⣿⣄⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⢀⣿⣿⣿⣿
|⣿⣿⣿⣷⡀⠈⠛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⣴⣿⣿⣿⣿⣿
|⣿⣿⣿⣿⣿⣶⣀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⢀⣴⣿⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⣿⣿⣿⣿⣿⣤⣀⠀⠉⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠋⠀⣀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
*********************************************/

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
#define size(x) ((int)x.size())

const int N = 1000005; // 1e6 + 5
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 998244353;

#define int long long

int n, m;
double aa = 0, bb = 0, pp = 0;
vector<int> a, b, atka, atkb, cnta(10, 0), cntb(10, 0);
void solve();
void dfs(bool xs, double p);
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout<< setiosflags(ios::fixed) << setprecision(10);
    // int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}

// #define int long long

void dfs(bool xs, double p) {

    // cout << xs << " : " <<endl;
    // for(int i = 0; i < n; ++ i) cout << a[i] << " "; cout <<endl;
    // for(int i = 0; i < n; ++ i) cout << cnta[i] << " "; cout <<endl;
    // for(int i = 0; i < m; ++ i) cout << b[i] << " "; cout <<endl;
    // for(int i = 0; i < m; ++ i) cout << cntb[i] << " "; cout <<endl;

    bool wa = 1, wb = 1;
    for(auto i : a) if(i > 0) wa = 0;
    for(auto i : b) if(i > 0) wb = 0;
    // cout << wa << " " << wb <<endl;
    if(wa && wb) pp += p;
    else if(wa) bb += p;
    else if(wb) aa += p;
    if(wa || wb) return;

    int ati = -1, siz = 0;
    if(xs) {
        for(int i = 0; i < m; (b[i ++] > 0 ? ++ siz : 0));
        p /= siz;
        for(int i = 0; i < n; ++ i) {
            if(a[i] <= 0) continue;
            if(ati == -1) {
                ati = i;
            }else if(cnta[ati] > cnta[i]) ati = i;
        }
        for(int i = 0; i < m; ++ i) {
            if(b[i] <= 0) continue;
            b[i] -= atka[ati], a[ati] -= atkb[i], ++ cnta[ati]; //, ++ cntb[i];
            dfs(!xs, p);
            b[i] += atka[ati], a[ati] += atkb[i], -- cnta[ati]; //, -- cntb[i];
        }
    }else {
        for(int i = 0; i < n; (a[i ++] > 0 ? ++ siz : 0));
        p /= siz;
        for(int i = 0; i < m; ++ i) {
            if(b[i] <= 0) continue;
            if(ati == -1) {
                ati = i;
            }else if(cntb[ati] > cntb[i]) ati = i;
        }
        for(int i = 0; i < n; ++ i) {
            if(a[i] <= 0) continue;
            a[i] -= atkb[ati], b[ati] -= atka[i], ++ cntb[ati]; //, ++ cnta[i];
            dfs(!xs, p);
            a[i] += atkb[ati], b[ati] += atka[i], -- cntb[ati]; //, -- cnta[i];
        }
    }
}

void solve() {
    cin>> n >> m;
    for(int i = 0, k; i < n; ++ i) {
        cin>> k;
        a.push_back(k);
        atka.push_back(k);
    }
    for(int i = 0, k; i < m; ++ i) {
        cin>> k;
        b.push_back(k);
        atkb.push_back(k);
    }
    for(int i = 0; i < 8; ++ i) cnta[i] = 0, cntb[i] = 0;
    if(n > m) dfs(1, 1);
    else if(m > n) dfs(0, 1);
    else {
        dfs(0, 0.5);
        dfs(1, 0.5);
    }
    // for(int i = 0; i < n; ++ i) cout << a[i] << " "; cout <<endl;
    // for(int i = 0; i < m; ++ i) cout << b[i] << " "; cout <<endl;
    cout << aa << endl << bb << endl << pp <<endl;
} 
