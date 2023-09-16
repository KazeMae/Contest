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
// #define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5

struct info{
    int minv, mincnt;
};
info operator + (const info &l, const info &r) {
    info a;
    a.minv = min(l.minv, r.minv);
    if (l.minv == r.minv) a.mincnt = l.mincnt + r.mincnt;
    else if(l.minv < r.minv) a.mincnt = l.mincnt;
    else a.mincnt = r.mincnt;
    return a;
}

struct SEGT{
    int n;
    struct node{
        info val;
    };
    vector<node> seg;
    SEGT(int len) : n(len), seg(n * 4) {}

    void update(int id) {
        seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
    }

    // 初始化
    void init(int id, int l, int r, vector<int> &a) {
        if(l == r) {
            seg[id].val = {a[l], 1};
        }else {
            int mid = l + r >> 1;
            init(id * 2, l, mid, a);
            init(id * 2 + 1, mid + 1, r, a);
            update(id);
        }
    }

    // 节点为id, 对应的区间为[l, r], 修改 a[pos] -> val
    void change(int id, int l, int r, int pos, int val) {
        if(l == r) {
            seg[id].val = {val, 1};
        }else {
            int mid = l + r >> 1;
            if(pos <= mid) change(id * 2, l, mid, pos, val);
            else change(id * 2 + 1, mid + 1, r, pos, val);
            update(id);
        }
    }
    // [ql, qr] 表示查询区间
    info query(int id, int l, int r, int ql, int qr) {
        if(l == ql && r == qr) return seg[id].val;
        int mid = l + r >> 1;
        // [l, mid] , [mid + 1, r]
        if(qr <= mid) return query(id * 2, l, mid, ql, qr); 
        else if(ql > mid) return query(id * 2 + 1, mid + 1, r, ql, qr);
        else {
            // qr > mid, ql <= mid
            // [ql, mid], [mid + 1, qr]
            return query(id * 2, l, mid, ql, mid) + query(id * 2 + 1, mid + 1, r, mid + 1, qr);
        }
        // update(id);
    }
};

signed main () {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q;
    cin>> n >> q;
    vector<int> a(n + 5);
    SEGT tree(n);
    for(int i = 1; i <= n; ++ i) {
        cin>> a[i];
    }
    tree.init(1, 1, n, a);
    for(int i = 0; i < q; ++ i) {
        int ty;
        cin>> ty;
        if(ty == 1) {
            int x, d;
            cin>> x >> d;
            tree.change(1, 1, n, x, d);
        }else {
            int l, r;
            cin>> l >> r;
            auto ans = tree.query(1, 1, n, l, r);
            cout<< ans.minv << " " << ans.mincnt <<endl;
        }
    }
}
