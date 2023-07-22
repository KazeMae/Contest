/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime 2023-07-21 13:33:42
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1000005; // 1e6 + 5

void solve() {
    int y, x;
    cin>> x;
    string xs = to_string(x), ys;
    bool flag = true;
    for(int i = 0; i <= 9 ; i ++) {
        int k = sqrt((x * (int)pow(10, i)));
        // cout<< k <<endl;
        ys = to_string(k * k);
        flag = true;
        for(int j = 0; j < xs.size(); j++) {
            if(xs[j] != ys[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << k <<endl;
            return;
        }
        ys = to_string((k + 1) * (k + 1));
        flag = true;
        for(int j = 0; j < xs.size(); j++) {
            if(xs[j] != ys[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << k + 1 <<endl;
            return;
        }
    }
    cout<< -1 <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
