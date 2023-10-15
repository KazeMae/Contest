/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: P3373 【模板】线段树 2
| Contest: Luogu
| URL:     https://www.luogu.com.cn/problem/P3373
| When:    2023-10-16 02:19:09
| 
| Memory:  125 MB
| Time:    1000 ms
*******************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

#define int long long
const int N = 1000005; // 1e6 + 5

struct SEGT {
    #define ls id << 1
    #define rs id << 1 | 1
    long long MOD;
    struct Zhenen {
        long long val, t, mul = 1;
        int sz;
    };
    vector<int> a;
    vector<Zhenen> seg;
    SEGT(int n, int mod) : MOD(mod), a(n + 1), seg(n * 4) {}

    void update(int id) {
        seg[id].val = (seg[ls].val + seg[rs].val) % MOD;
    }

    void settag(int id, int mul, int t) {
        seg[id].val = ((seg[id].val * mul) % MOD + (seg[id].sz * t) % MOD) % MOD;
        seg[id].mul = (seg[id].mul * mul) % MOD;
        seg[id].t = (seg[id].t * mul + t) % MOD;
    }

    void pushdown(int id) {
        if(seg[id].t != 0 || seg[id].mul != 1) {
            settag(ls, seg[id].mul, seg[id].t);
            settag(rs, seg[id].mul, seg[id].t);
            seg[id].t = 0, seg[id].mul = 1;
        }
    }

    void build(int id, int l, int r) {
        seg[id].sz = r - l + 1, seg[id].mul = 1;
        if(l == r) seg[id].val = a[l];
        else {
            int mid = l + r >> 1;
            build(ls, l, mid);
            build(rs, mid + 1, r);
            update(id);
        }
    }

    void modify(int id, int l, int r, int ql, int qr, long long mul, long long t) {
        if(l == ql && r == qr) {
            settag(id, mul, t);
            return;
        }
        pushdown(id);
        int mid = l + r >> 1;
        if(qr <= mid) modify(ls, l , mid, ql, qr, mul, t);
        else if(ql > mid) modify(rs, mid + 1, r, ql, qr, mul, t);
        else {
            modify(ls, l, mid, ql, mid, mul, t);
            modify(rs, mid + 1, r, mid + 1, qr, mul, t);
        }
        update(id);
    }

    long long query(int id, int l, int r, int ql, int qr) {
        if(l == ql && r == qr) return seg[id].val;
        pushdown(id);
        int mid = l + r >> 1;
        if(qr <= mid) return query(ls, l, mid, ql, qr) % MOD;
        else if(ql > mid) return query(rs, mid + 1, r, ql, qr) % MOD;
        else return (query(ls, l, mid, ql, mid) + query(rs, mid + 1, r, mid + 1, qr)) % MOD;
    }
    #undef ls
    #undef rs
};

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q, m;
    cin>> n >> q >> m;
    SEGT tr(n, m);
    for(int i = 1; i <= n; ++ i) {
        cin>> tr.a[i];
    }
    tr.build(1, 1, n);
    while(q --) {
        int op, x, y, k;
        cin>> op >> x >> y;
        if(op == 1) {
            cin>> k;
            tr.modify(1, 1, n, x, y, k, 0);
        }else if(op == 2) {
            cin>> k;
            tr.modify(1, 1, n, x, y, 1, k);
        }else cout<< tr.query(1, 1, n, x, y) <<endl;
    }
}

