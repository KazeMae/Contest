#include <bits/stdc++.h> 
using namespace std;


void solve() {
    int n, sum = 1, cnt = 1, ql = 0, ans = 0;
    cin>> n;
    for(int i = 0; i < n; ++ i) {
        int op;
        cin>> op;
        if(op == 1) {
            cnt ++, sum ++;
        }else if(op == -1) {
            if(cnt >= 2) cnt --;
            else if(ql > 0) sum ++, ql --, cnt ++;
            else ans = -1;
        }else {
            if(cnt >= 2)
                ql ++, cnt --;
            else cnt ++, sum ++;
        }
    }
    if(ans == -1) {
        cout<< -1 <<endl;
        return;
    }else {
        cout<< sum / __gcd(sum, cnt) << " " << cnt / __gcd(sum, cnt) <<endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin>> t;
    while(t --) {
        solve();
    }
}
