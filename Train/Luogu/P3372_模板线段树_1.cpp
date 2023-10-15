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

struct SEGT {
    #define ls id << 1
    #define rs id << 1 | 1
    struct Zhenen {
        long long val, t = 0;
        int sz;
    };
    vector<int> a;
    vector<Zhenen> seg;
    SEGT(int n) : a(n + 1), seg(n * 4) {}

    void update(int id) {
        seg[id].val = seg[ls].val + seg[rs].val;
    }


    void pushdown(int id) {
        if(seg[id].t != 0) {
            seg[ls].val += seg[ls].sz * seg[id].t;
            seg[rs].val += seg[rs].sz * seg[id].t;
            seg[ls].t += seg[id].t;
            seg[rs].t += seg[id].t;
            seg[id].t = 0;
        }
    }

    void build(int id, int l, int r) {
        seg[id].sz = r - l + 1;
        if(l == r) seg[id].val = a[l];
        else {
            int mid = l + r >> 1;
            build(ls, l, mid);
            build(rs, mid + 1, r);
            update(id);
        }
    }

    void modify(int id, int l, int r, int ql, int qr, long long t) {
        if(l == ql && r == qr) {
            seg[id].val += seg[id].sz * t;
            seg[id].t += t;
            return;
        }
        pushdown(id);
        int mid = l + r >> 1;
        if(qr <= mid) modify(ls, l , mid, ql, qr, t);
        else if(ql > mid) modify(rs, mid + 1, r, ql, qr, t);
        else {
            modify(ls, l, mid, ql, mid, t);
            modify(rs, mid + 1, r, mid + 1, qr, t);
        }
        update(id);
    }

    long long query(int id, int l, int r, int ql, int qr) {
        if(l == ql && r == qr) return seg[id].val;
        pushdown(id);
        int mid = l + r >> 1;
        if(qr <= mid) return query(ls, l, mid, ql, qr);
        else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
        else return (query(ls, l, mid, ql, mid) + query(rs, mid + 1, r, mid + 1, qr));
    }
    #undef ls
    #undef rs
};

signed main () {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    cin>> n >> m;
    SEGT tr(n);
    for(int i = 0; i < n; ++ i) {
        cin>> tr.a[i + 1];
    }
    tr.build(1, 1, n);
    while(m --) {
        int op, x, y, k;
        cin>> op >> x >> y;
        if(op == 1) {
            cin >> k;
            tr.modify(1, 1, n, x, y, k);
        }else cout<< tr.query(1, 1, n, x, y) <<endl;
    }
}
