/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime 2023-07-19 15:58:19
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin>> n;
    vector<int> v(n);
    vector<bool> st(n);
    for(int i = 0; i < n; i++) {
        cin>> v[i];
        // cout<< v[i] << " ";
    }
    int now = 0, ding = 0, ll = 0, lr = 0;
    for(int i = 0; i < n; i ++) {
        if(now > 0) {
            now --;
            if(!st[i]) {
                st[i] = 1;
                ll ++;
            }
        }
        if(v[i] > now) {
            now = v[i];
        }
    }
    now = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(now > 0) {
            now --;
            if(!st[i]) {
                st[i] = 1;
                lr ++;
            }
        }
        if(v[i] > now) {
            now = v[i];
        }
    }
    cout<< lr + ll <<endl;
}
