/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: E. Physical Education Lessons
| Contest: Codeforces - Educational Codeforces Round 36 (Rated for Div. 2)
| URL:     https://codeforces.com/contest/915/problem/E
| When:    2023-11-09 23:46:10
| 
| Memory:  256 MB
| Time:    1000 ms
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
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks") 
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

// #define endl '\n'

struct DSEGT {
    #define ls(id) seg[id].l
    #define rs(id) seg[id].r

    int tot = 1, root = 1;
    const int MX = 300005; // 3e5

    struct Zhenen {
        int sum = 0, l = 0, r = 0, lazy = -1;
    } ept;
    vector<Zhenen> seg;

    DSEGT() : seg(MX * 50) {}

    void update(int id) {
        seg[id].sum = seg[ls(id)].sum + seg[rs(id)].sum;
    }

    void pushdown(int id, int l, int r) {
        if(seg[id].lazy == -1) return;
        if(!ls(id)) ls(id) = ++ tot;
        if(!rs(id)) rs(id) = ++ tot;

        seg[ls(id)].lazy = seg[id].lazy;
        seg[rs(id)].lazy = seg[id].lazy;

        int mid = (l + r - 1) / 2;

        seg[ls(id)].sum = (mid - l + 1) * seg[id].lazy;
        seg[rs(id)].sum = (r - mid) * seg[id].lazy;
        seg[id].lazy = -1;
    }
    // 区间修改 [l, r] += t
    void modify(int id, int l, int r, int ql, int qr, int t) {
        if(!id) id = ++ tot;
        if(ql <= l && qr >= r) {
            seg[id].lazy = t, seg[id].sum = (r - l + 1) * t;
        }else {
            pushdown(id, l, r);
            int mid = (l + r - 1) / 2;
            if(ql <= mid) modify(ls(id), l, mid, ql, qr, t);
            if(qr > mid) modify(rs(id), mid + 1, r, ql, qr, t);
            update(id);
        }
    }
    // 查询 [ql, qr] 的区间和
    int query(int id, int l, int r, int ql, int qr) {
        if(l >= ql && r <= qr) {
            return seg[id].sum;
        }
        pushdown(id, l, r);
        int mid = (l + r - 1) / 2, ans = 0;
        if(ql <= mid) ans += query(ls(id), l, mid, ql, qr);
        if(qr > mid) ans += query(rs(id), mid + 1, r, ql, qr);
        return ans;
    }

    // void build(int pos, int k) {build(root, _l_, _r_, pos, k); } // 创建点
    // void modify(int ql, int qr, int t) {modify(1, _l_, _r_, ql, qr, t); } // 区间修改
    // void add(int pos, int k) {build(1, _l_, _r_, pos, k); } // pos 位置, 增加 k 
    // void insert(int x){add(x, 1); } // 插入
    // void del(int x) {add(x, -1); } // 删除
    // int query(int ql, int qr) {query(1, _l_, _r_, ql, qr); } // 区间求和
    // int rank(int x) {return query(_l_, x - 1) + 1; } // 求 x 的排名
    // int kth(int k) {return kth(1, _l_, _r_, k); } // 第 k 大数
    // int pre(int x) {return kth(rnk(x) - 1); } // 求前驱数个数
    // int next(int x) {return kth(rnk(x + 1)); } // 求后继数个数

    #undef _l_
    #undef _r_

    #undef ls
    #undef rs
};

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q, cnt = 0;
    cin>> n >> q;
    DSEGT tr;

    // cout<< ++ cnt << " <" <<endl;
    tr.modify(1, 1, n, 1, n, 1);
    // cout<< cnt << " >" <<endl;
    while(q --) {
        int l, r, k;
        cin>> l >> r >> k;
        // cout<< ++ cnt << " <" <<endl;
        if(k == 1) tr.modify(1, 1, n, l, r, 0);
        else tr.modify(1, 1, n, l, r, 1);
        // cout<< cnt << " >" <<endl;
        cout<< tr.query(1, 1, n, 1, n) <<endl;
        // cout<< cnt << " >>" <<endl;
        // for(int i = 1; i <= n; ++ i) cout << tr.query(1, 1, n, i, i) << " "; cout <<endl;
    }
    return 0;
}
