#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define abs(x) (x < 0 ? -x : x)


signed main() {
    int n, t, mx = 0;
    cin>> n >> t;
    std::vector<int> a(n);
    for(int i = 0; i < n; ++ i) {
        cin>> a[i];
        mx = max(mx, a[i]);
    }
    cout<< (mx / t + (mx % t != 0) > 2 ? mx / t + (mx % t != 0) : 2 ) <<endl;
}
