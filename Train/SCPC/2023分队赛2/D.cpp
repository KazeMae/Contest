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
    struct info {
        int cl = 0, cr = 0;
    };
    vector<info> seg;
    SEGT(int n) : seg(n * 4) {}

    void update(int id) {
        seg[id].cl = seg[ls].cl + seg[rs].cl;
        seg[id].cr = seg[ls].cr + seg[rs].cr;
    }

    void build(int id, int l, int r, string s) {
        if(l == r) {
            if(s[l - 1] == '<') seg[id].cl = 1;
            else seg[id].cr = 0;
        }else {
            int mid = l + r >> 1;
            build(ls, l, mid, s);
            build(rs, mid + 1, r, s);
            update(id);
        }
    }

    void change(int id, int l, int r, int pos, char c) {
        if(l == r) {
            if(c == '<') seg[id].cl = 1, seg[id].cr = 0;
            else seg[id].cr = 1, seg[id].cl = 0;
        }else {
            int mid = l + r >> 1;
            if(pos <= mid) change(ls, l, mid, pos, c);
            else change(rs, mid + 1, r, pos, c);
            update(id);
        }
    }

    int query(int id, int l, int r, int ql, int qr, char c) {
        if(l == ql && r == qr) {
            if(c == '<') return seg[id].cl;
            else return seg[id].cr;
        }else {
            int mid = l + r >> 1;
            if(qr <= mid) return query(ls, l, mid, ql, qr, c);
            else if(ql > mid) return query(rs, mid + 1, r, ql, qr, c);
            else return query(ls, l, mid, ql, mid, c) + query(rs, mid + 1, r, mid + 1, qr, c);
        }
    }
    #undef ls
    #undef rs
};

void solve();
signed main () {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t; while(t --)
        solve();
}
#define int long long

void solve() {
    int n, ans = 0x3f3f3f3f3f3f3f3f, sum = 0, rsum = 0;
    string s;
    cin>> n;
    // cout << n <<endl;
    // SEGT tr(n + 10);
    cin>> s;
    // cout << s <<endl;

    for(int i = n - 1; i >= 0; -- i) {
        if(s[i] == '>') ++ rsum;
        else sum += rsum;
    }
    ans = min(sum, ans);
    for(int j = n - 1; j >= 0; -- j) {
        if(s[j] == '>') {
            s[j] = '<';
            sum = 0, rsum = 0;
            for(int i = n - 1; i >= 0; -- i) {
                if(s[i] == '>') ++ rsum;
                else sum += rsum;
            }
            ans = min(sum, ans);
            s[j] = '>';
            break;
        }
    }
    for(int j = 0; j < n; ++ j) {
        if(s[j] == '<') {
            s[j] = '>';
            sum = 0, rsum = 0;
            for(int i = n - 1; i >= 0; -- i) {
                if(s[i] == '>') ++ rsum;
                else sum += rsum;
            }
            ans = min(sum, ans);  
            s[j] = '<';
            break;
        }
    }
    
    cout << ans <<endl;
    // tr.build(1, 1, n, s);
    // for(int i = 0; i < n; ++ i) {
    //     if(s[i] == '<') sum += tr.query(1, 1, n, i, n, '>');
    // }
    // cout << sum <<endl;
    // ans = min(sum, ans);
    // for(int i = n - 1; i >= 0; -- i) {
    //     if(s[i] == '>') {
    //         s[i] = '<';
    //         tr.change(1, 1, n, i + 1, '<');
    //         break;
    //     }
    // }
    // for(int i = 0; i < n; ++ i) {
    //     if(s[i] == '<') sum += tr.query(1, 1, n, i, n, '>');
    // }
    // ans = min(sum, ans);
    // cout << ans <<endl;
}
