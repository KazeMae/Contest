/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1000005; // 1e6 + 5

void solve() {
    int n; ll k;
    cin>> n >> k;
    string s;
    cin>> s;
    if(n == 1) {
        if(k % 2) cout<< (s[0] == '0' ? 1 : 0) <<endl;
        else cout<< (s[0] == '1' ? 1 : 0) <<endl;
        return;
    }
    if(k == 0) {
        cout<< s <<endl;
        return;
    }
    vector<int> v;
    if(k != 0) v.push_back(1);
    else v.push_back((s[0] == '1' ? 1 : 0));
    for(int i = 1; i < n; i++) {
        if(k == 0) v.push_back((s[i] == '1' ? 1 : 0));
        else {
            if(s[i] == '0' && i + 1 == n || s[i - 1] == '0' && s[i] == '1')
                v.push_back(1), k--;
            else if(s[i] == '0') v.push_back(1);
            else v.push_back((s[i] == '1' ? 1 : 0));
        }
    }
    if(!(k&1)) {
        for(auto i:v) cout<< i;
    }else {
        v.back() = 0;
        for(auto i:v) cout<< i;
    }
    cout<<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
