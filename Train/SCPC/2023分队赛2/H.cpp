#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5
void solve();
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --) {
        solve();
    }
}

void solve() {
    int n, ansi = 0, ansj = 0;; 
    cin>> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++ i) {
        cin>> a[i];
    }
    for(int i = 0; i < n; ++ i) {
        for(int j = i + 1; j < n; ++ j) {
            if(__gcd(a[i], a[j]) == a[i]) {
                ansi = i, ansj = j;
                break;
            } 
            if(__gcd(a[i], a[j]) == a[j]) {
                ansi = j, ansj = i;
                break;
            }
        }
    }
    cout<< n <<endl;
    cout << 2 << " " << ansi + 1 << " " << ansj + 1 <<endl;
    for(int i = 0; i < n; ++ i) {
        if(i == ansi) continue;
        cout << 2 << " " << ansi + 1 << " " << i + 1 <<endl;
    }
}
