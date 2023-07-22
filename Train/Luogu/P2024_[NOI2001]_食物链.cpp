/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P2024 [NOI2001] 食物链
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P2024
| When:    2023-07-22 19:35:26
| 
| Memory:  125 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
int p[N], w[N];

int find(int x) {
    if(x != p[x]) {
        int root = find(p[x]);
        w[x] += w[p[x]];
        p[x] = root;
    }
    return p[x];
}

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k, ans = 0;
    cin>> n >> k;
    for(int i = 0; i <= n; i++) p[i] = i, w[i] = 1;
    for(int i = 0; i < k; i++) {
        int op, a, b;
        cin>> op >> a >> b;
        if(a > n || b > n) ans ++;
        else if(op == 1) {
            if(p[a] == a || p[b] == b)
                p[a] = p[b], find(a), find(b);
            else if(abs(w[a] - w[b]) % 3 != 0) ans ++;
        }else {
            if(p[a] == a || p[b] == b)
                p[b] = a, find(a), find(b);
            else if(abs(w[a] - w[b]) % 3 != 1) ans ++;
        }
        cout<< op << " " << a << " " << b << " " << ans << " " << w[a] << " " << w[b]<<endl;
    }
    cout<< ans <<endl;
}
