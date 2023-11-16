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
        long long val;
    };
    vector<int> a;
    vector<Zhenen> seg;
    SEGT(int n) : a(n + 1), seg(n * 4) {}

    void update(int id) {
        seg[id].val = max(seg[ls].val, seg[rs].val);
    }


    void pushdown(int id) {
        
    }

    void build(int id, int l, int r) {
        if(l == r) seg[id].val = a[l];
        else {
            int mid = l + r >> 1;
            build(ls, l, mid);
            build(rs, mid + 1, r);
            update(id);
        }
    }
    // 修改 [ql, qr] 为 t
    void modify(int id, int l, int r, int ql, int qr, long long t) {
        if(l == ql && r == qr) {
            seg[id].val = t;
            return;
        }
        // pushdown(id);
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
    // 寻找 [ql, qr] 大于等于 d 的第一个数的下标, 不存在返回 -1
    int search(int id, int l, int r, int ql, int qr, int d) {
        if(l == ql && r == qr) {
            if(seg[id].val < d) return -1;
            else {
                if(l == r) return l;
                int mid = l + r >> 1;
                if(seg[ls].val >= d) return search(ls, l, mid, ql, mid, d);
                else return search(rs, mid + 1, r, mid + 1, qr, d);
            }
        }
        // pushdown(id);
        int mid = l + r >> 1;
        if(qr <= mid) return search(ls, l, mid, ql, qr, d);
        else if(ql > mid) return search(rs, mid + 1, r, ql, qr, d);
        else {
            int pos = search(ls, l, mid, ql, mid, d);
            if(pos == -1) return search(rs, mid + 1, r, mid + 1, qr, d);
            else return pos;
        }
    }
    #undef ls
    #undef rs
};

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q;
    cin>> n >> q;
    SEGT tr(n);
    for(int i = 1; i <= n; ++ i) 
        cin>> tr.a[i];
    tr.build(1, 1, n);
    while(q --) {
        int op;
        cin>> op;
        if(op == 1) {
            int x, d;
            cin>> x >> d;
            tr.modify(1, 1, n, x, x, d);
        }else if(op == 2) {
            int l, r, d;
            cin>> l >> r >> d;
            cout << tr.search(1, 1, n, l, r, d) <<endl;;
        }
    }
}
