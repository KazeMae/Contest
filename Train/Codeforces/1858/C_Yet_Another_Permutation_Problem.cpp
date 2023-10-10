/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C. Yet Another Permutation Problem
| Contest: Codeforces Round 893 (Div. 2)
| URL:     https://codeforces.com/contest/1858/problem/C
| When:    2023-08-15 22:47:44
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

const int N = 1000005; // 1e6 + 5
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;

// void get_primes(int n)
// {
//     for (int i = 2; i <= n; i ++ )
//     {
//         if (!st[i]) primes[cnt ++ ] = i;
//         for (int j = 0; primes[j] <= n / i; j ++ )
//         {
//             st[primes[j] * i] = true;
//             if (i % primes[j] == 0) break;
//         }
//     }
// }

void solve() {
    int n;
    cin>> n;
    vector<int> ans;
    vector<bool> st(n + 5);
    for(int i = 1; i <= n; ++ i) {
        int k = i;
        while(k <= n) {
            if(st[k] == 0) ans.push_back(k), st[k] = 1;
            k *= 2;
        }
    }
    for(auto i:ans) cout<< i << " "; cout<<endl;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
