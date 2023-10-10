#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define abs(x) (x > 0 ? (x) : (-x))
const double PI = acos(-1);


void solve() {
    cout<<setiosflags(ios::fixed)<<setprecision(10);
    double c1x1, c1y1, c1x2, c1y2, c2x1, c2y1, c2x2, c2y2;
    cin >> c1x1 >> c1y1 >> c1x2 >> c1y2 >> c2x1 >> c2y1 >> c2x2 >> c2y2;
    double c1x = (c1x1 + c1x2) * 1.0 / 2, c1y = (c1y1 + c1y2) * 1.0 / 2;
    double c2x = (c2x1 + c2x2) * 1.0 / 2, c2y = (c2y1 + c2y2) * 1.0 / 2;
    // double k = (c1y - c2y) / (c1x - c2x);
    // double seta = atan(k);
    // cout<< seta <<endl;
    double dis = sqrtl((c1x - c2x) * (c1x - c2x) + (c1y - c2y) * (c1y - c2y));
    double si = abs(c1y - c2y) / dis;
    double co = abs(c1x - c2x) / dis;
    double disx = abs(c1x - c2x);
    double disy = abs(c1y - c2y);
    double r1 = sqrtl((c1x1 - c1x2) * (c1x1 - c1x2) + (c1y1 - c1y2) * (c1y1 - c1y2)) / 2;
    double r2 = sqrtl((c2x1 - c2x2) * (c2x1 - c2x2) + (c2y1 - c2y2) * (c2y1 - c2y2)) / 2;
    double l, r;
    if(c1x > c2x && c1y > c2y) {
        l = 0, r = PI / 2;
    }else if(c1x < c2x && c1y > c2y) {
        l = PI / 2, r = PI;
    }else if(c1x < c2x && c1y < c2y) {
        l = PI, r = PI / 2 * 3;
    }else l = PI / 2 * 3, r = PI * 2;

    auto check = [&] (double mid) {
        disx = c2x + r2 * cos(mid), disy = c2y + r2 * sin(mid);
        return abs(disx - c1x) + abs(disy - c1y);
    };

    while(abs(r - l) > 1e-7) {
        double x = (2 * l + r) / 3;
        double y = (2 * r + l) / 3;
        if(check(x) < check(y)) r = y;
        else l = x;
    }
    cout << check(l) <<endl;
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
}
