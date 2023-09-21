#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define abs(x) (x > 0 ? (x) : (-x))

void solve() {
    double c1x1, c1y1, c1x2, c1y2, c2x1, c2y1, c2x2, c2y2;
    cin>> c1x1 >> c1y1 >> c1x2 >> c1y2 >> c2x1 >> c2y1 >> c2x2 >> c2y2;
    double c1x = (c1x1 + c1x2) * 1.0 / 2, c1y = (c1y1 + c1y2) * 1.0 / 2;
    double c2x = (c2x1 + c2x2) * 1.0 / 2, c2y = (c2y1 + c2y2) * 1.0 / 2;
    // double k = (c1y - c2y) / (c1x - c2x);
    // double seta = atan(k);
    // cout<< seta <<endl;
    double dis = sqrt((c1x - c2x) * (c1x - c2x) + (c1y - c2y) * (c1y - c2y));
    double si = abs(c1y - c2y) / dis;
    double co = abs(c1x - c2x) / dis;
    double disx = abs(c1x - c2x);
    double disy = abs(c1y - c2y);
    double r1 = sqrt((c1x1 - c1x2) * (c1x1 - c1x2) + (c1y1 - c1y2) * (c1y1 - c1y2)) / 2;
    double r2 = sqrt((c2x1 - c2x2) * (c2x1 - c2x2) + (c2y1 - c2y2) * (c2y1 - c2y2)) / 2;
    cout<< dis - r2 <<endl;
    cout<< disx - r2 * si << endl << disy - r2 * co <<endl;
    double xsk = (dis - r2) / r1;
    double sek = atan(sek);
    cout << xsk << " " << sek << " " << sin(sek) <<endl;
    printf("%.9lf\n",(disx + disy - r2 * si - r2 * co));
}   

signed main() {
    int t = 1;
    // cin>> t;
    while(t --) {
        // solve();
       printf("%.9lf", (4.270518393147 - 4.2639320225));
    }
}
