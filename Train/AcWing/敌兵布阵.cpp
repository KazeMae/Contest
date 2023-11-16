/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         
 * @DateTime    
 */
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
typedef long long ll;
typedef pair<int, int> PII;
// #define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5


struct SEGT{
    int n;
    struct Zhenen{
        int val;//, size, t = 0;
    };
    vector<int> a;
    vector<Zhenen> seg;
    SEGT(int n) : a(n + 5), seg(n * 4) {}

    void update(int id) {
        seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
    }
    // void pushdown(int id) {
    //     if(!seg[id].t) continue;
    //     seg[id * 2].val = seg[id * 2].val + seg[id].t * seg[id * 2].size;
    //     seg[id * 2 + 1].val = seg[id * 2 + 1].val + seg[id].t * seg[id * 2 + 1].size;
    //     seg[id * 2].t = seg[id].t;
    //     seg[id * 2 + 1].t = seg[id].t;
    //     seg[id].t = 0;
    // }

    // 初始化
    void init(int id, int l, int r) {
        // seg[id].size = r - l + 1;
        if(l == r) {
            seg[id].val = a[l];
        }else {
            int mid = l + r >> 1;
            init(id * 2, l, mid);
            init(id * 2 + 1, mid + 1, r);
            update(id);
        }
    }

    // 节点为id, 对应的区间为[l, r], 修改 a[pos] -> val
    void change(int id, int l, int r, int pos, int val) {
        if(l == r) {
            seg[id].val += val;
        }else {
            // pushdown(id);
            int mid = l + r >> 1;
            if(pos <= mid) change(id * 2, l, mid, pos, val);
            else change(id * 2 + 1, mid + 1, r, pos, val);
            update(id);
        }
    }
    // [ql, qr] 表示查询区间
    int query(int id, int l, int r, int ql, int qr) {
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
void solve();
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin>> t;
    for(int i = 1; i <= t; ++ i) {
        cout << "Case " << i << ":" <<endl;
        solve();
    }
}

void solve() {
    int n, x, y;
    cin>> n;
    SEGT tr(n);
    for(int i = 1; i <= n; ++ i) {
        cin>> tr.a[i];
    }
    tr.init(1, 1, n);
    while(1) {
        string s;
        cin>> s;
        if(s == "Add") {
            cin>> x >> y; 
            tr.change(1, 1, n, x, y);
        }else if(s == "Sub") { 
            cin>> x >> y; 
            tr.change(1, 1, n, x, -y);
        }else if(s == "Query") {
            cin>> x >> y; 
            cout<< tr.query(1, 1, n, x, y) <<endl;
        }else break;
    }
}
