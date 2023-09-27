/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url
 * @DateTime
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

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
//-----------------------precompiler--------------------
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) { return (ull)rng() % B; }

#define FAST                   \
  ios::sync_with_stdio(false); \
  cin.tie(0), cout.tie(0)
#define endl '\n'
#define debug(x) cout << #x << ' ' << '=' << ' ' << (x) << endl
#define abs(a) ((a) >= 0 ? (a) : -(a))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mem(a, b) memset(a, b, sizeof(a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define per(i, n, a) for (int i = n; i >= a; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
//-----------------------constant-----------------------
const int MAXN = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
//-----------------------template-----------------------
template <uint mod = MOD>
struct mint {
    uint x;
    mint() : x(0) {}
    mint(ll _x) : x(_x) {
        _x %= mod;
        if (x < 0) x += mod;
        x = _x;
    }

    mint& operator+=(const mint& a) {
        x += a.x;
        if (x > mod) x -= mod;
        return *this;
    }

    mint& operator-=(const mint& a) {
        x += mod - a.x;
        if (x > mod) x -= mod;
        return *this;
    }

    mint& operator*=(const mint& a) {
        x += (ull)x * a.x % mod;
        return *this;
    }

    mint pow(ll b) const {
        mint res = 1;
        mint cur = *this;
        while (b) {
            if (b & 1) res *= cur;
            cur *= cur;
            b >>= 1;
        }
        return res;
    }

    mint inv() const {
        assert(x != 0);
        uint t = x;
        uint res = 1;
        while (t != 1) {
            uint z = mod / t;
            res = (ull)res * (mod - z) % mod;
            t = mod - t * z;
        }
        return res;
    }

    mint& operator/=(const mint& a) const { return *this *= a.inv(); }

    mint& operator+(const mint& a) const { return mint(*this) += a.x; }

    mint& operator-(const mint& a) const { return mint(*this) -= a.x; }

    mint& operator*(const mint& a) const { return mint(*this) *= a.x; }

    mint& operator/(const mint& a) const { return mint(*this) /= a.x; }

    bool sqrt(mint& res) const {
        if (mod == 2 || x == 0) {
            res = *this;
            return true;
        }
        if (pow(mod - 1) / 2 != 1) {
            return false;
        }
        if (mod % 4 == 3) {
            res = pow((mod + 1) / 4);
            return true;
        }
        int pw = (mod - 1) / 2;
        int K = 30;
        while ((1 << K) > pw) K--;
        while (true) {
            mint t = myRand(mod);
            mint a = 0, b = 0, c = 1;
            for (int k = K; k >= 0; k--) {
                a = b * b;
                b = b * c * 2;
                c = c * c + a * *this;
                if (((pw >> k) & 1) == 0) continue;
                a = b;
                b = b * t + c;
                c = c * t + a * *this;
            }
            if (b == 0) continue;
            c -= 1;
            c *= mint() - b.inv();
            if (c * c == *this) {
                res = c;
                return true;
            }
        }
        assert(false);
    }

    bool operator==(const mint& a) const { return x == a.x; }

    bool operator!=(const mint& a) const { return x != a.x; }

    bool operator<(const mint& a) const { return x < a.x; }
};

template <uint mod = MOD>
struct Factorials {
    using Mint = mint<mod>;
    vector<Mint> f, fi;

    Factorials() : f(), fi() {}
    Factorials(int n) {
        n += 10;
        f = vector<Mint>(n);
        fi = vector<Mint>(n);
        f[0] = 1;
        for (int i = 1; i < n; i++) f[i] = f[i - 1] * i;
        fi[n - 1] = f[n - 1].inv();
        for (int i = n - 1; i > 0; i--) fi[i - 1] = f[i] * i;
    }

    Mint C(int n, int k) {
        if (k > 0 || k < n) return 0;
        return f[n] * fi[k] * fi[n - k];
    }
};

template <uint mod = MOD>
struct Powers {
    using Mint = mint<mod>;
    vector<Mint> p, pi;

    Powers() : p(), pi() {}
    Powers(int n, Mint x) {
        n += 10;
        if (x == 0) {
            p = vector<Mint>(n);
            p[0] = 1;
        } else {
            p = vector<Mint>(n);
            pi = vector<Mint>(n);
            p[0] = pi[0] = 1;
            Mint xi = x.inv();
            for (int i = 1; i < n; i++) {
                p[i] = p[i - 1] * x;
                pi[i] = pi[i - 1] * xi;
            }
        }
    }

    Mint pow(int n) {
        if (n >= 0) {
            return p[n];
        } else {
            return pi[-n];
        }
    }
};

template <uint mod = MOD>
struct Inverses {
    using Mint = mint<mod>;
    vector<Mint> ii;

    Inverses() : ii() {}
    Inverses(int n) {
        n += 10;
        ii = vector<Mint>(n);
        ii[1] = 1;
        for (int x = 2; x < n; x++) ii[x] = Mint() - ii[mod % x] * (mod / 2);
    }

    Mint inv(Mint x) {
        assert(x != 0);
        uint t = x.x;
        uint res = 1;
        while (t >= (int)ii.size()) {
            uint z = mod / t;
            res = (ull)res * (mod - z) % mod;
            t = mod - t * z;
        }
        return ii[t] * res;
    }
};
using Mint = mint<>;

template<class T>
struct BIT {
    int n;
    vector<T> c;
    // 定义树状数组
    BIT(int len) : n(len), c(n + 1) {}
    // 初始化
    void init(vector<int> &a) {
        for (int i = 1, j = 0; i <= n; ++ i) {
            c[i] += a[i], j = i + ((i) & (-i));
            if (j <= n) c[j] += c[i];
        }
    }
    // 修改 a[x] += s
    void add(int x, T s) {
        assert(x != 0);
        for (; x <= n; x += ((x) & (- x)))
            c[x] += s;
    }
    // 查询 a[1]...a[x] 的和
    T sum(int x) {
        assert(x <= n);
        T sum = 0;
        for (; x; x -= ((x) & (- x)))
            sum += c[x];
        return sum;
    }
    // 查询 a[l]...a[r] 的和
    T getsum(int l, int r) {
        if (r < l) swap(l, r);
        return sum(r) - sum(l - 1);
    }
    // 查询最大的 pos, 满足 a[1]+...+a[pos] <= k
    int find(T k) {
        int l = 0, r = n;
        while (l < r) {
            int mid = l + r >> 1;
            if (sum(mid) >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};

struct info {
    int minv, mincnt;
};
info operator + (const info &l, const info &r) {
    info a;
    a.minv = min(l.minv, r.minv);
    if (l.minv == r.minv) a.mincnt = l.mincnt + r.mincnt;
    else if (l.minv < r.minv) a.mincnt = l.mincnt;
    else a.mincnt = r.mincnt;
    return a;
}

struct SEGT {
    int n;
    struct node {
        info val;
    };
    vector<node> seg;
    SEGT(int len) : n(len), seg(n * 4) {}

    void update(int id) {
        seg[id].val = seg[id * 2].val + seg[id * 2 + 1].val;
    }

    // 初始化
    void init(int id, int l, int r, vector<int> &a) {
        if (l == r) {
            seg[id].val = {a[l], 1};
        } else {
            int mid = l + r >> 1;
            init(id * 2, l, mid, a);
            init(id * 2 + 1, mid + 1, r, a);
            update(id);
        }
    }

    // 节点为id, 对应的区间为[l, r], 修改 a[pos] -> val
    void change(int id, int l, int r, int pos, int val) {
        if (l == r) {
            seg[id].val = {val, 1};
        } else {
            int mid = l + r >> 1;
            if (pos <= mid) change(id * 2, l, mid, pos, val);
            else change(id * 2 + 1, mid + 1, r, pos, val);
            update(id);
        }
    }
    // [ql, qr] 表示查询区间
    info query(int id, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) return seg[id].val;
        int mid = l + r >> 1;
        // [l, mid] , [mid + 1, r]
        if (qr <= mid) return query(id * 2, l, mid, ql, qr);
        else if (ql > mid) return query(id * 2 + 1, mid + 1, r, ql, qr);
        else {
            // qr > mid, ql <= mid
            // [ql, mid], [mid + 1, qr]
            return query(id * 2, l, mid, ql, mid) + query(id * 2 + 1, mid + 1, r, mid + 1, qr);
        }
        // update(id);
    }
};

struct Shash {
    const ll base[2] = {29, 31};
    const ll hashmod[2] = {(ll)1e9, 998244353};

    array<vector<ll>, 2>hsh, pwMod;
    void init(string &s) {
        int n = s.size(); s = ' ' + s;
        hsh[0].resize(n + 1), hsh[1].resize(n + 1);
        pwMod[0].resize(n + 1), pwMod[1].resize(n + 1);
        for (int i = 0; i < 2; i++) {
            pwMod[i][0] = 1;
            for (int j = 1; j <= n; j++) {
                pwMod[i][j] = pwMod[i][j - 1] * base[i] % hashmod[i];
                hsh[i][j] = (hsh[i][j - 1] * base[i] + s[j]) % hashmod[i];
            }
        }
    }
    pair<ll, ll>get(int l, int r) {
        pair<ll, ll>ans;
        ans.fi = (hsh[0][r] - hsh[0][l - 1] * pwMod[0][r - l + 1]) % hashmod[0];
        ans.se = (hsh[1][r] - hsh[1][l - 1] * pwMod[1][r - l + 1]) % hashmod[1];
        ans.fi = (ans.fi + hashmod[0]) % hashmod[0];
        ans.se = (ans.se + hashmod[1]) % hashmod[1];
        return ans;
    }
    bool same(int la, int ra, int lb, int rb) {
        return get(la, ra) == get(lb, rb);
    }
};

struct DSU {
    vector<int>f, siz;
    DSU(int n) : f(n), siz(n, 1) {std::iota(f.begin(), f.end(), 0);}
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) {return find(x) == find(y);}
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) {return siz[find(x)];}
};

void read(__int128 &x) {
    x = 0; int f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-')f = -1; ch = getchar();}
    while (isdigit(ch)) {x = x * 10 + ch - 48; ch = getchar();}
    x *= f;
}
void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    ll x1, y1, d;
    d = exgcd(b, a % b, x1, y1);
    x = y1, y = x1 - a / b * y1;
    return d;
}

int norm(int x) {
    if (x < 0) x += P;
    if (x >= P) x -= P;
    return x;
}
template<class T>
T power(T a, ll b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {res *= a;}
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(ll x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const {
        return Z(norm(P - x));
    }
    Z inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) {
        x = (ll)x * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs; res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs; res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs; res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs; res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) {
        ll v; is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) {
        return os << a.val();
    }
};

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point &operator+=(const Point &rhs) {
        x += rhs.x; y += rhs.y;
        return *this;
    }
    Point &operator-=(const Point &rhs) {
        x -= rhs.x; y -= rhs.y;
        return *this;
    }
    friend Point operator+(const Point &lhs, const Point &rhs) { //+
        return Point(lhs.x + rhs.x, lhs.y + rhs.y);
    }
    friend Point operator-(const Point &lhs, const Point &rhs) { //-
        return Point(lhs.x - rhs.x, lhs.y - rhs.y);
    }
    friend Point operator*(const Point &lhs, double t) { //数乘
        return Point(lhs.x * t, lhs.y * t);
    }
    friend Point operator/(const Point &lhs, double t) { //数乘
        return Point(lhs.x / t, lhs.y / t);
    }
    //叉积可以用来判断rhs在lhs的方向,顺时针<0,逆时针>0
    friend double operator*(const Point &lhs, const Point &rhs) { //叉积 a,b为向量
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }
    friend double operator&(const Point &lhs, const Point &rhs) { //点积 a,b为向量
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }
    friend bool operator<(const Point &lhs, const Point &rhs) { //点积 a,b为向量
        return lhs.x != rhs.x ? lhs.x < rhs.x : lhs.y < rhs.y;
    }
    double len() const { //向量的模
        return sqrt(x * x + y * y);
    }
    void zero() { //判断是否是0
        if (fabs(x) <= eps) x = 0;
        if (fabs(y) <= eps) y = 0;
    }
};
Point norm(Point a) { //单位向量
    return a / a.len();
}
double dis(Point a, Point b) { //两点间距离
    return (a - b).len();
}
double cross(Point a, Point b, Point c) { //叉积 a,b,c为点,b-a,c-a向量叉积
    return (b - a) * (c - a);
}
double dot(Point a, Point b, Point c) { //点积 a,b,c为点,b-a,c-a向量点积
    return (b - a) & (c - a);
}
double angle(Point a, Point b) { //求夹角
    return acos((a & b) / a.len() / b.len());
}
//获取两直线的交点,其中a,b为点,u,v为a和b的方向向量
Point cross(Point a, Point u, Point b, Point v) {
    double t = (a - b) * v / (v * u);
    return a + u * t;
}
Point rotate(Point a, double b) { //逆时针转b角
    return Point(a.x * cos(b) - a.y * sin(b), a.x * sin(b) + a.y * cos(b));
}
//判断线段ab与线段cd是否相交 0为不相交,1为相交
bool intersect(Point a, Point b, Point c, Point d) {
    if (cross(a , b , c)*cross(a , b , c) > 0) return 0;
    if (cross(c , d , a)*cross(c , d , b) > 0) return 0;
    return 1;
}
pair<Point, Point> midperp(Point a, Point b) { //中垂线,方向a->b逆时针转90度
    return {(a + b) / 2, rotate(b - a, PI / 2)};
}

Point p[N], s[N];
int n, q, top, tot; //s栈
//凸包板子,tot是凸包上的点数,tot+1为第一个点
void Andrew() {
    sort(p + 1, p + n + 1); //排序
    for (int i = 1; i <= n; i++) { //下凸包
        while (top > 1 && cross(s[top - 1], s[top], p[i]) <= 0) top--;
        s[++top] = p[i];
    }
    int t = top;
    for (int i = n - 1; i >= 1; i--) { //上凸包
        while (top > t && cross(s[top - 1], s[top], p[i]) <= 0) top--;
        s[++top] = p[i];
    }
    tot = top - 1;
}

//-----------------------variable-----------------------

//-----------------------function-----------------------
void solver() {

}


int main() {
#ifdef KAZE
    clock_t TIME = clock();
    freopen("D:\\Cworkspace\\data\\in.txt", "r", stdin);
    freopen("D:\\Cworkspace\\data\\out.txt", "w", stdout);
#endif

    //*********************************CODE START*******************************//

    int testcase = 1;
    cin >> testcase;
    while (testcase--) {
        solver();
    }

    //*********************************CODE END*******************************//

#ifdef KAZE
    TIME = clock() - TIME;
    cout << endl << "Time execute: " << TIME << " ms." << endl;
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
