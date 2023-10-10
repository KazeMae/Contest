/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: B. Permutations &amp; Primes
| Contest: Codeforces Round  884 (Div. 1 + Div. 2)
| URL:     https://codeforces.com/contest/1844/problem/B
| When:    2023-07-11 22:38:58
| 
| Memory:  256 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n;
    cin>> n;
    if(n == 2) cout<< "2 1" <<endl;
    else if(n == 1) cout << 1 <<endl;
    else {
        deque<int> q;
        for(int i = 1; i <= n; i++) {
            if(i == 2 || i == 3) continue;
            if(i % 2) {
                q.push_front(i);
            }else q.push_back(i);
        }
        q.push_front(3);
        q.push_back(2);
        while(!q.empty()) {
            cout<< q.front() <<" ";
            q.pop_front();
        }
        cout<<endl;
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
/**
 *6 5 2 1 4 3 8 7
 */
