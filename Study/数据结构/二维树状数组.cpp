/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         
 * @DateTime    
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5

template<class T>
struct BITT {
    int n, m;
    vector<vector<T> > c;
    // 定义树状数组
    BITT(int len, int lem) : n(len), m(lem), c(n + 1, vector<T> (m + 1)) {}
    // 初始化
    void init(vector<vector<int> > &a) {
        for(int i = 1; i <= n; ++ i) {
            for(int j = 1; j <= m; ++ j) {
                add(i, j, a[i][j]);
            }
        }
    }
    // 修改 a[x] += s
    void add(int x, int y, T s) {
        assert(x != 0);
        assert(y != 0);
        for(int p = x; p <= n; p += p & (-p))
            for(int q = y; q <= m; q += q & (-q))
                c[p][q] += s;
    }
    // 查询 a[1][1]...a[x][y] 的和
    T sum(int x, int y) {
        assert(x <= n);
        assert(y <= m);
        T sum = 0;
        for(int p = x; p ; p -= p & (-p))
            for(int q = y; q ; q -= q & (-q))
                sum += c[p][q];
        return sum;
    }
    // 查询 a[u][d]...a[l][r] 子矩阵的和
    T getsum(int u, int d, int l, int r) {
        return sum(l, r) + sum(u - 1, d - 1) - sum(l, d - 1) - sum(u - 1, r);
    }
};

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, op;
    cin>> n >> m;
    BITT<long long> tree(n, m);
    while(cin>> op) {
        if(op == 1) {
            int x, y, k;
            cin>> x >> y >> k;
            tree.add(x, y, k);
        }else {
            int a, b, c, d;
            cin>> a >> b >> c >>d;
            cout<< tree.getsum(a, b, c, d) <<endl;
        }
    }
}
