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

struct Fenwick {
    const int n;
    vector<long long> c;
    // 定义树状数组
    Fenwick(int len) : n(len), c(n + 1) {}
    // 初始化
    void init(vector<int> &a) {
        for(int i = 1, j = 0; i <= n; ++ i) {
            c[i] += a[i], j = i + ((i) & (-i));
            if(j <= n) c[j] += c[i];
        }
    }
    // 修改 a[x] += s
    void add(int x, long long s) {
        for(; x <= n; x += ((x) & (- x)))
            c[x] += s;
    }
    // 查询 a[1]...a[x] 的和
    long long sum(int x) {
        long long sum = 0;
        for(; x; x -= ((x) & (- x))) 
            sum += c[x];
        return sum;
    }
    // 查询 a[l]...a[r] 的和
    long long getsum(int l, int r) {
        if(r < l) swap(l, r);
        return sum(r) - sum(l - 1);
    }
};

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    long long ans = 0;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> mp;
    for (int i = 0; i < n; ++ i) {
        cin >> a[i + 1];
        a[i + 1] = n - a[i + 1] + 1;
        mp[a[i + 1]] = i + 1;
    }
    Fenwick tree(n);
    for(int i = 1; i <= n; ++ i) {
        ans += tree.sum(a[i]);
        tree.add(a[i], 1);
    }
    cout<< ans <<endl;
}
