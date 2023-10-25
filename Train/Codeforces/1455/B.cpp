/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         
 * @DateTime    
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

int x, cnt = 0;

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 1});
    while(!q.empty()) {
        int now = q.front().first, k = q.front().second;
        q.pop();
        if(now - 1 == x || now + k == x) {
            cnt = k;
            return;
        } else {
            q.push({now + k, k + 1});
            q.push({now - 1, k + 1});
        }
    }
}
// #define int long long

void solve() {
    x = 0, cnt = 0;
    int now = 0;
    cin>> x;
    for(int i = 1; now < x; ++ i, ++ cnt) 
        now += i;
    int ans = now - x + cnt;
    for(int i = 1; i <= cnt; ++ i) {
        if(now - i - 1 == x) ans = min(ans, cnt);
    }
    cout<< ans <<endl;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // cout<< setiosflags(ios::fixed) << setprecision(10);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}

