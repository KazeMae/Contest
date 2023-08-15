/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Puzzle: Square Jam
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57363/E
| When:    2023-08-14 12:28:10
| 
| Memory:  524288 MB
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

// #define int long long

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

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

const int MAXN = 1000005; // 1e6 + 5
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin>> n >> m;
    vector<int> a, b, c;
    int l = 0, r = 0;
    while((n - l) == (m - r)) {
        if((n - l) > (m - r)) {
            a.push_back(l);
            b.push_back(r);
            c.push_back(m - r);
            l = m - r;
            r = m - r;
        }else if((n - l) < (m - r)) {
            a.push_back(l);
            b.push_back(r);
            c.push_back(n - l);
            l = n - l;
            // r = n - l;
        }else {
            a.push_back(l);
            b.push_back(r);
            c.push_back(n - l);
            break;
        }
    }
    cout<< "YES" << endl << a.size() <<endl;
    for(int i = 0; i < a.size(); ++ i) {
        cout<< a[i] << ' ' << b[i] << ' ' << c[i] <<endl;
    }
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
