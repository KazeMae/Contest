/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: E - Lucky bag
| Contest: AtCoder - AtCoder Beginner Contest 332
| URL:     https://atcoder.jp/contests/abc332/tasks/abc332_e
| When:    2023-12-11 12:21:35
| 
| Memory:  1024 MB
| Time:    2000 ms
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


void solve();
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout<< setiosflags(ios::fixed) << setprecision(18);
    // int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
#define int long long

void solve() {
    srand(time(0));
    int n, d, sum = 0, tot = 0;
    double ans = 1e18, anss = 0;
    cin>> n >> d;
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i = 0; i < n; ++ i) {
        cin>> a[i];
        sum += a[i];
    }
    double p = sum * 1.0 / d;
    for(int i = 0; i < d; ++ i) q.push(0);
    sort(a.begin(), a.end());
    for(int i = 0; i < n; ++ i) {
        int t = q.top();
        q.pop();
        q.push(t + a[i]);
    }
    anss = 0;
    while(!q.empty()) {
        anss += ((p - q.top()) * (p - q.top()));
        // cout << q.top() << " ";
        q.pop();
    }
    ans = min(anss / d, ans);
    for(int i = 0; i < d; ++ i) q.push(0);
    sort(a.begin(), a.end(), greater<int> ());
    for(int i = 0; i < n; ++ i) {
        int t = q.top();
        q.pop();
        q.push(t + a[i]);
    }
    anss = 0;
    while(!q.empty()) {
        anss += ((p - q.top()) * (p - q.top()));
        // cout << q.top() << " ";
        q.pop();
    }
    ans = min(anss / d, ans);
    int timess = 1500000;
    while(timess --) {
        for(int i = 0; i < d; ++ i) q.push(0);
        random_shuffle(a.begin(), a.end());
        for(int i = 0; i < n; ++ i) {
            int t = q.top();
            q.pop();
            q.push(t + a[i]);
        }
        double anss = 0;
        while(!q.empty()) {
            anss += ((p - q.top()) * (p - q.top()));
            // cout << q.top() << " ";
            q.pop();
        }
        // cout << endl;
        ans = min(anss / d, ans);
    }
    cout<< ans <<endl;
} 
// 3 3 3 5 6
// 3 // 20 / 3 = 6.66 , 3 + 3 = 6, 3 + 5 = 8, 6
