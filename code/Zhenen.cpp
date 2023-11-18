#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define endl '\n'


void solve();
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // int t = 0; cin >> t; while(t --)
        solve();
}

void solve() {
    int x, y, di, dv, ma, mb, da, db;
    cin>> x >> y >> di >> dv;
    int gd = __gcd(di, dv);
    int lm = di / gd * dv;
    if(gd != 1) {
        int ca = max(x, y) / (di - 1);
        int ta = di * ca - 1;
        ma = ta;
        for(int i = ta, cnt = ca; cnt < max(x, y); ++ i, ++ cnt, ma = i);
        cout << ma <<endl;
    }else {
        int ca = y / (dv - 1); // !di
        int ta = dv * ca - 1;
        ma = ta;
        for(int i = (ta < 1 ? 1 : ta), cnt = ca; cnt < y; ma = max(ma, i ++), ++ cnt);
        da = ma;
        // cout << ma <<endl;
        int cb = x / (di - 1); // !dv
        int tb = di * cb - 1;
        mb = tb;
        for(int i = (tb < 1 ? 1 : tb), cnt = cb; cnt < x; mb = max(mb, i ++), ++ cnt);
        db = mb;
        // cout << mb <<endl;
        // cout << "ma, mb : " << ma << " " << mb <<endl;
        // di
        int kca = x / di;
        int kta = di * kca - 1;
        ma = max(ma, kta);
        // cout << "ka : " << kta << " " << dv <<endl;
        for(int i = (kta < 1 ? dv : kta), cnt = kca; cnt < x; ma = max(ma, i), (i >= da ? ((i + 1) % di == 0 ? i += 2 : i ++) : i += dv), ++ cnt);

        // dv
        int kcb = y / dv;
        int ktb = dv * kcb - 1;
        // cout << "kb : " << ktb << " " << db <<endl;
        mb = max(mb, ktb);
        for(int i = (ktb < 1 ? di : ktb), cnt = kcb; cnt < y; mb = max(mb, i), (i >= db ? ((i + 1) % dv == 0 ? i += 2 : i ++) : i += di), ++ cnt); //{cout << mb <<endl;};
        // cout << "ma, mb : " << ma << " " << mb <<endl;

        cout << min(ma, mb) <<endl;
    }
}
