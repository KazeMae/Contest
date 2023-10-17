/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C. Factorials and Powers of Two
| Contest: Codeforces - Codeforces Round 774 (Div. 2)
| URL:     https://codeforces.com/contest/1646/problem/C
| When:    2023-10-17 22:46:05
| 
| Memory:  256 MB
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

using ll = long long;
using Ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using PII = pair<int, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
#define endl '\n'

// #define int long long

vector<long long> v;
vector<pair<long long, int>> bl;
int getbit(long long m) {
    int k = 0;
    while(m) {
        k += m % 2;
        m /= 2;
    }
    return k;
}

pair<long long, int> getsum(int n) {
    long long sum = 0;
    int c = 0;
    for(int i = 13; i >= 0; -- i) {
        if(n >= (1ll << i)) {
            sum += v[i];
            n -= (1ll << i);
            c ++;
        }
    }
    return {sum, c};
}

void solve() {
    long long n;
    cin>> n;
    int ans = getbit(n);
    for(auto i:bl) {
        if(n - i.first < 0) continue;
        ans = min(ans, getbit(n - i.first) + i.second);
    }
    cout<< ans <<endl;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long jk = 1;
    for(int i = 1; i <= 14; ++ i) {
        jk *= i;
        v.push_back(jk);
    }
    for(int i = 0; i <= 16384; ++ i) 
        bl.push_back(getsum(i));
    
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
