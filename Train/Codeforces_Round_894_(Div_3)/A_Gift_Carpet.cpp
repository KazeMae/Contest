/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Gift Carpet
| Contest: Codeforces Round 894 (Div. 3)
| URL:     https://codeforces.com/contest/1862/problem/A
| When:    2023-08-24 22:37:41
| 
| Memory:  256 MB
| Time:    1000 ms
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
#define lowbit(x) x&(-x)

const int N = 1000005; // 1e6 + 5
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 998244353;

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

void solve() {
    int n, m, flag = 0;
    cin>> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; ++ i) {
        cin>> s[i];
    }
    vector<int> v, k, ii, a;
    for(int i = 0; i < m; ++ i) {
        for(int j = 0; j < n; ++ j) {
            if(s[j][i] == 'v') v.push_back(i);
            if(s[j][i] == 'i') ii.push_back(i);
            if(s[j][i] == 'k') k.push_back(i);
            if(s[j][i] == 'a') a.push_back(i);
        }
    }
    if(m < 4) {
        cout<< "NO" <<endl;
        return;
    }
    if(v.empty() || ii.empty() || k.empty() || a.empty()) {
        cout<< "NO" <<endl;
        return;
    }
    v.erase(unique(v.begin(), v.end()), v.end());
    ii.erase(unique(ii.begin(), ii.end()), ii.end());
    k.erase(unique(k.begin(), k.end()), k.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    
    for(auto i1:v) {
        for(auto i2:ii) {
            for(auto i3:k){
                for(auto i4:a){
                    if(i1 < i2 && i2 < i3 && i3 < i4){
                        cout<< "YES" <<endl;
                        return;
                    }
                }
            }
        }
    }
    cout<< "NO" <<endl;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
