/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: D. Row Major
| Contest: Codeforces Round  884 (Div. 1 + Div. 2)
| URL:     https://codeforces.com/contest/1844/problem/D
| When:    2023-07-12 00:20:18
| 
| Memory:  256 MB
| Time:    2000 ms
*******************************/
/**
 * WA
 */

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    sort(res.begin(), res.end());
    return res;
}
bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}

void solve() {
    int n, k;
    cin>> n;
    if(n == 1) {
        cout<< 'z' <<endl;
        return;
    }
    if(is_prime(n)) {
        for(int i = 0; i < n; i++) {
            if(i % 2) cout<< 'a';
            else cout<< 'b';
        }
        cout<<endl;
        return;
    }
    auto v = get_divisors(n);
    for(auto i = -- v.end(); i != v.begin(); i --) {
        if(is_prime(*i)) {
            k = *i;
            break;
        }
    }
    char c = 'a';
    k = k + 1;
    // cout<< (n / k) * k + n % k <<endl;
    for(int i = 0; i < n / k; i++) {
        c = 'a';
        for(int j = 0; j < k; j++) {
            cout<< (char)(c++);
        }
        c ++;
        if(c > 'z') c = 'a';
    }
    c = 'a';
    for(int i = 0; i < n % k; i++) {
        cout<< (char)c;
        c ++;
        if(c > 'z') c = 'a';
    }
    cout<<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
