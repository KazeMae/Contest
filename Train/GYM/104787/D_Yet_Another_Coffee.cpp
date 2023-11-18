/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: D. Yet Another Coffee
| Contest: Codeforces - The 2023 CCPC (Qinhuangdao) Onsite (The 2nd Universal Cup. Stage 9: Qinhuangdao)
| URL:     https://codeforces.com/gym/104787/problem/D
| When:    2023-11-16 13:26:36
| 
| Memory:  256 MB
| Time:    2000 ms
*******************************/

/*
* ⣇⣿⠘⣿⣿⣿⡿⡿⣟⣟⢟⢟⢝⠵⡝⣿⡿⢂⣼⣿⣷⣌⠩⡫⡻⣝⠹⢿⣿⣷
* ⡆⣿⣆⠱⣝⡵⣝⢅⠙⣿⢕⢕⢕⢕⢝⣥⢒⠅⣿⣿⣿⡿⣳⣌⠪⡪⣡⢑⢝⣇
* ⡆⣿⣿⣦⠹⣳⣳⣕⢅⠈⢗⢕⢕⢕⢕⢕⢈⢆⠟⠋⠉⠁⠉⠉⠁⠈⠼⢐⢕⢽
* ⡗⢰⣶⣶⣦⣝⢝⢕⢕⠅⡆⢕⢕⢕⢕⢕⣴⠏⣠⡶⠛⡉⡉⡛⢶⣦⡀⠐⣕⢕
* ⡝⡄⢻⢟⣿⣿⣷⣕⣕⣅⣿⣔⣕⣵⣵⣿⣿⢠⣿⢠⣮⡈⣌⠨⠅⠹⣷⡀⢱⢕
* ⡝⡵⠟⠈⢀⣀⣀⡀⠉⢿⣿⣿⣿⣿⣿⣿⣿⣼⣿⢈⡋⠴⢿⡟⣡⡇⣿⡇⡀⢕
* ⡝⠁⣠⣾⠟⡉⡉⡉⠻⣦⣻⣿⣿⣿⣿⣿⣿⣿⣿⣧⠸⣿⣦⣥⣿⡇⡿⣰⢗⢄
* ⠁⢰⣿⡏⣴⣌⠈⣌⠡⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣬⣉⣉⣁⣄⢖⢕⢕⢕
* ⡀⢻⣿⡇⢙⠁⠴⢿⡟⣡⡆⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣵⣵⣿
* ⡻⣄⣻⣿⣌⠘⢿⣷⣥⣿⠇⣿⣿⣿⣿⣿⣿⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
* ⣷⢄⠻⣿⣟⠿⠦⠍⠉⣡⣾⣿⣿⣿⣿⣿⣿⢸⣿⣦⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟
* ⡕⡑⣑⣈⣻⢗⢟⢞⢝⣻⣿⣿⣿⣿⣿⣿⣿⠸⣿⠿⠃⣿⣿⣿⣿⣿⣿⡿⠁⣠
* ⡝⡵⡈⢟⢕⢕⢕⢕⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⣿⠿⠋⣀⣈⠙
* ⡝⡵⡕⡀⠑⠳⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⢉⡠⡲⡫⡪⡪⡣
*/

// #include <bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

#define endl '\n'

const int N = 1000005; // 1e6 + 5
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 998244353;

// #define int long long

#define int long long

struct SEGT {
    #define ls id << 1
    #define rs id << 1 | 1

    struct Zhenen {
        long long mn, t = 0;
        int idx;
    };

    vector<int> a;
    vector<Zhenen> seg;

    SEGT(int n) : a(n + 5), seg(n * 4) {}

    void update(int id) {
        if(seg[ls].mn <= seg[rs].mn) 
            seg[id].mn = seg[ls].mn, seg[id].idx = seg[ls].idx;
        else 
            seg[id].mn = seg[rs].mn, seg[id].idx = seg[rs].idx;
    }

    void pushdown(int id) {
        if(seg[id].t == 0) return;
        seg[ls].mn += seg[id].t;
        seg[rs].mn += seg[id].t;
        seg[ls].t += seg[id].t;
        seg[rs].t += seg[id].t;
        seg[id].t = 0;
    }

    void bulid(int id, int l, int r) {
        if(l == r) seg[id].mn = a[l], seg[id].idx = l;
        else {
            int mid = l + r >> 1;
            bulid(ls, l ,mid);
            bulid(rs, mid + 1 ,r);
            update(id);
        }
    }

    void change(int id, int l, int r, int pos, long long val) {
        if(l == r) {
            seg[id].mn = val;
        }else {
            pushdown(id);
            int mid = l + r >> 1;
            if(pos <= mid) change(ls, l, mid, pos, val);
            else change(rs, mid + 1, r, pos, val);
            update(id);
        }
    }

    void modify(int id, int l, int r, int ql, int qr, long long t) {
        if(ql == l && qr == r) {
            seg[id].mn += t;
            seg[id].t += t;
        }else {
            pushdown(id);
            int mid = l + r >> 1;
            if(qr <= mid) modify(ls, l, mid, ql, qr, t);
            else if(ql > mid) modify(rs, mid + 1, r, ql, qr, t);
            else {
                modify(ls, l, mid, ql, mid, t);
                modify(rs, mid + 1, r, mid + 1, qr, t);
            }
            update(id);
        }
    }

    pair<long long, int> query(int id, int l, int r, int ql, int qr) {
        if(ql == l && qr == r) return make_pair(seg[id].mn, seg[id].idx);
        else {
            pushdown(id);
            int mid = l + r >> 1;
            if(qr <= mid) return query(ls, l, mid, ql, qr);
            else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
            else return min(query(ls, l, mid, ql, mid), query(rs, mid + 1, r, mid + 1, qr));
        }
    }

    #undef ls
    #undef rs
};

void solve();
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // cout<< setiosflags(ios::fixed) << setprecision(10);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
// #define int long long

void solve() {
    int n, m;
    long long ans = 0;
    cin>> n >> m;
    SEGT tr(n);
    vector<pair<int, int> > mp;
    for(int i = 1; i <= n; ++ i) {
        cin>> tr.a[i];
    }
    tr.bulid(1, 1, n);
    while(m -- ) {
        int r = 0, w = 0;
        cin>> r >> w;
        mp.push_back({r, w});
        tr.modify(1, 1, n, 1, r, (-w));
    }
    sort(mp.begin(), mp.end());
    for(int i = 1; i <= n; ++ i) {
        auto res = tr.query(1, 1, n, 1, n);
        cout << ans + res.first <<" ";
        ans += res.first;
        tr.modify(1, 1, n, res.second, res.second, LNF);
        if(!mp.empty()) for(auto it = mp.end() - 1; it >= mp.begin(); -- it) {
            if(res.second > (*it).first) break;
            tr.modify(1, 1, n, 1, (*it).first, (*it).second);
            mp.erase(it);
        }
    }
    cout <<endl;
} 
