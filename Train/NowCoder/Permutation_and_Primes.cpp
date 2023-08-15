/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Permutation and Primes
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57362/J
| When:    2023-08-11 14:16:11
| 
| Memory:  1048576 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
const int MOD = 998244353;
bool is_prime(int x) {
    if (x <= 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

void solve() {
    int n;
    cin>> n;
    vector<int> d1(1, 0), d2(1, 0), d3(1, 0);
    for(int i = 1; i <= n; i++) {
        if(i % 3 == 1) d1.push_back(i);
        if(i % 3 == 2) d2.push_back(i);
        if(i % 3 == 0) d3.push_back(i);
    }
    if(is_prime(abs(d1.back() - 3)) || is_prime(d1.back() + 3)) {
        for(int i = d2.size() - 1; i >= 1; -- i) cout<< d2[i] <<" ";
        for(int i = 1; i < d1.size(); ++ i) cout<< d1[i] <<" ";
        for(int i = 1; i < d3.size(); ++ i) cout<< d3[i] <<" ";
    }else if(is_prime(abs(d2.back() - 3)) || is_prime(d2.back() + 3)) {
        for(int i = d1.size() - 1; i >= 1; -- i) cout<< d1[i] <<" ";
        for(int i = 1; i < d2.size(); ++ i) cout<< d2[i] <<" ";
        for(int i = 1; i < d3.size(); ++ i) cout<< d3[i] <<" ";
    }else if(is_prime(abs(d1.back() - d3.back())) || is_prime(d1.back() + d3.back())) {
        for(int i = d2.size() - 1; i >= 1; -- i) cout<< d2[i] <<" ";
        for(int i = 1; i < d1.size(); ++ i) cout<< d1[i] <<" ";
        for(int i = d3.size() - 1; i >= 1; -- i) cout<< d3[i] <<" ";
    }else if(is_prime(abs(d2.back() - d3.back())) || is_prime(d2.back() + d3.back())) {
        for(int i = d1.size() - 1; i >= 1; -- i) cout<< d1[i] <<" ";
        for(int i = 1; i < d2.size(); ++ i) cout<< d2[i] <<" ";
        for(int i = d3.size() - 1; i >= 1; -- i) cout<< d3[i] <<" ";
    }else if(is_prime(abs(d2.back() - 1)) || is_prime(d2.back() + 1)) {
        for(int i = d3.size() - 1; i >= 1; -- i) cout<< d3[i] <<" ";
        for(int i = 1; i < d2.size(); ++ i) cout<< d2[i] <<" ";
        for(int i = 1; i < d1.size(); ++ i) cout<< d1[i] <<" ";
    }else if(is_prime(abs(d3.back() - 1)) || is_prime(d3.back() + 1)) {
        for(int i = d2.size() - 1; i >= 1; -- i) cout<< d2[i] <<" ";
        for(int i = 1; i < d3.size(); ++ i) cout<< d3[i] <<" ";
        for(int i = 1; i < d1.size(); ++ i) cout<< d1[i] <<" ";
    }else if(is_prime(abs(d2.back() - d1.back())) || is_prime(d2.back() + d1.back())) {
        for(int i = d3.size() - 1; i >= 1; -- i) cout<< d3[i] <<" ";
        for(int i = 1; i < d2.size(); ++ i) cout<< d2[i] <<" ";
        for(int i = d1.size() - 1; i >= 1; -- i) cout<< d1[i] <<" ";
    }else if(is_prime(abs(d3.back() - d1.back())) || is_prime(d3.back() + d1.back())) {
        for(int i = d2.size() - 1; i >= 1; -- i) cout<< d2[i] <<" ";
        for(int i = 1; i < d3.size(); ++ i) cout<< d3[i] <<" ";
        for(int i = d1.size() - 1; i >= 1; -- i) cout<< d1[i] <<" ";
    }else cout<< -1;
    cout << endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
