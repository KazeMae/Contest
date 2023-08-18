#include <bits/stdc++.h>

using namespace std;
//#define int long long
typedef pair<int, int> PII;
#define fr(i, a, n) for(int i = a; i <= n; i ++)
#define rf(i, a, n) for(int i = n; i >= a; i --)
const int N = 200005;
const int mod = 1e9 + 7;
int T, t, n, m, a, b, idx, flag, ans, a1, b1, a2, b2, k, x, y, mx, mn;
int l, r, mid, c, mi, sum, cnt, d;
char cc;
string s, ss, s1, s2;
int q[N], p[N];
char path[5][5];

void solve()
{
    cin >> m >> k >> a >> b;
    ans = m / k;
    c = m % k;
//  cout << ans << endl;
    if(b >= ans)
    {
        if(c == 0)
        {
            cout << 0 << endl;
            return;
        }
        if(a >= c)
        {
            cout << 0 << endl;
            return;
        }
        cout << c - a << endl;
    }else
    {
        if(a + b * k >= m)
        {
            cout << 0 << endl;
            return;
        }
        m = m - b * k;
        b = 0;
        a -= m % k;
        sum = 0;
        if(a < 0) sum -= a;
        ans = a / k;
        sum += max((m / k) - ans, 0);
        cout << sum << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> T;
    while(T -- )
        solve();
    return 0;
} 
