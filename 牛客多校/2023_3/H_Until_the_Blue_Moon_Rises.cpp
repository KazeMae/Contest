/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Until the Blue Moon Rises
| Contest: NowCoder
| URL:     https://ac.Nowcoder.com/acm/contest/57357/H
| When:    2023-07-24 12:31:04
| 
| Memory:  524288 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void divide(int x)
{
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;
            cout << i << ' ' << s << endl;
        }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
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
    int n, sum = 0;
    cin>> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>> a[i];
        sum += a[i];
    }
/*    if(sum < n * 2) cout << "No";
    else */if(n == 1) cout << (is_prime(sum) ? "Yes" : "No");
    else if(n == 2) cout << (sum % 2 == 0 || is_prime(sum - 2) ? "Yes" : "No");
    else cout<< (sum > (n - 3) * 2 + 5 ? "Yes" : "No");
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
