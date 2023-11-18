#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'


signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin>> n;
    map<int, int> mp;
    for(int i = 0, qwe; i < n; ++ i) {
        cin>> qwe;
        mp[qwe] ++;
    }
    bool isban = 0;
    for(auto [x, y] : mp) {
        if(y > n / 2) {
            isban = 1, k = y;
            break;
        }
    }
    if(k == n) cout << 0 <<endl;
    else if(!isban) {
        cout << n;
        cout << "000000000000000000";
    }else {
        if((n - k) * 2 != 0) {
            cout << (n - k) * 2;
            cout << "000000000000000000";
        }else cout << 0 <<endl;
    }
    
}
