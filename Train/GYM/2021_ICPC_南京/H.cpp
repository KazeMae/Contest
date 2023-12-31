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
ll myRand(ll B) { 
    return (ull)rng() % B; 
}

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
#define lowbit(x) ((x) & (-x))

const int N = 1000005; // 1e6 + 5
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 998244353;

// #define int long long

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

void solve() {
    int n, cnt = 0;
    cin>> n;
    vector<int> a(n), b;
    for(int i = 0; i < n; ++ i) 
        cin>> a[i];
    b = a;
    for(int k = 1; k <= n; ++ k) {
        int cnt = 0;
        a = b;
        // cout<< "unsort:" <<endl;
        // for(int j = 0; j < k; ++ j) {
        //         cout<< a[j] << " ";
        // }cout<<endl;
        for(int i = 0; i < k; ++ i) {
            for(int j = 0; j < k; ++ j) {
                if(a[j] > a[i]) {
                    swap(a[i], a[j]);
                    cnt ++;
                    cout<< "info: ";
                cout<< i << " " << j << " " << cnt << " " << a[i] << " " << a[j] <<endl;
                cout<< "sort:" <<endl;
                for(int m = 0; m < n; ++ m) {
                        cout<< a[m] << " ";
                }cout<<endl<<endl;
                }
            }
            
        }
        cout<< "ans: " << cnt << endl;
    }
    cout<< endl;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
// 1 2 2 3 5 // 5 // + 1
// 1 2 2 5 3 // 4 // + 2
// 2 2 5 1 3 // 3 // + 1
// 2 5 2 1 3 // 2 // + 1
// 5 2 2 1 3 // 1 // + 2
// 2 3 2 1 5 // 0

