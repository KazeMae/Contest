#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
char a[105][104], b[105][104]; //a[]类型为char[104]
char c[105], d[105];
int main(void) {
    // std::ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t, t1 = 0, t2 = 0;
    cin >> t;
    while (t--) {
        fill(c, c + 104, '0');
        fill(d, d + 104, '0');
        t1 = 0, t2 = 0;
        int m, n;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (strlen(a[i]) > t1) {
                t1 = strlen(a[i]);
            }
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            if (strlen(b[i]) > t2) {
                t2 = strlen(b[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (strlen(a[i]) == t1) {
                if (strcmp(a[i], c) > 0) {
                    strcpy(c, a[i]);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (strlen(b[i]) == t2) {
                if (strcmp(b[i], d) > 0) {
                    strcpy(d, b[i]);
                }
            }
        }
        if (strcmp(c, d) > 0) {
            cout << c << d << endl;
        } else cout << d << c << endl;
    }
    return 0;
}
