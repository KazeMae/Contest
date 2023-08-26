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
    vector<T> c;
    // 定义树状数组
    BIT(int len) : n(len), c(n + 1) {}
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
    // 查询最大的 pos, 满足 a[1]+...+a[pos] <= k, 配合权值树状数组实现查询第 k 小
    int find(T k) {
        int pos = 0;
        // 
        for(int j = 30; j >= 0; -- j) {
            if(pos + (1 << j) <= n && c[pos + (1 << j)] <= k) {
                pos += (1 << j);
                k -= c[pos];
            }
        }
        return pos;
    }
};

signed main () {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q;
    cin>> n >> q;
    BIT<long long> tree(n);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; ++ i) {
        cin>> a[i];
        tree.add(i, a[i]);
    }
    while(q --) {
        int op, x;
        long long s;
        cin >> op;
        if(op == 1) {
            cin >> x >> s;
            tree.add(x, s - a[x]);
            a[x] = s;
        }else {
            cin>> s;
            cout<< tree.find(s) <<endl;
        }
    }
}
