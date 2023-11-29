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
struct BIT {
    int n;
    vector<T> c, d;
    // 定义树状数组
    BIT(int len) : n(len), c(n + 1), d(n + 1) {}
    // 初始化
    void init(vector<int> &a) {
        for(int i = 1, j = 0; i <= n; ++ i) {
            c[i] += a[i], j = i + ((i) & (-i));
            if(j <= n) c[j] += c[i];
        }
    }
    // 修改 a[x] += s
    void add(int x, T s) {
        assert(x != 0);
        for(; x <= n; x += ((x) & (- x)))
            c[x] += s;
    }
    // 查询 a[1]...a[x] 的和
    T sum(int x) {
        assert(x <= n);
        T sum = 0;
        for(; x; x -= ((x) & (- x))) 
            sum += c[x];
        return sum;
    }
    // 查询 a[l]...a[r] 的和
    T getsum(int l, int r) {
        if(r < l) swap(l, r);
        return sum(r) - sum(l - 1);
    }
};

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin>> n >> m;
    vector<int> a(n + 1), d(n + 1); // 原数组, 差分数组
    for(int i = 1; i <= n; ++ i) {
        cin>> a[i];
        d[i] = a[i] - a[i - 1];
    }
    BIT<long long> tree1(n), tree2(n);
    tree1.init(d);
    while(m --) {
        int op, l, r, k;
        cin>> op;
        if(op == 1) {
            cin>> l >> r >> k;
            tree1.add(l, k);
            tree1.add(r + 1, -k);
            tree2.add(l, l * k);
            tree2.add(r + 1, (r + 1) * (-k));
        }else {
            cin>> k;
            long long ans = (k + 1) * tree1.sum(k) - tree2.sum(k);
            cout<< ans <<endl;
        }
    }
}
