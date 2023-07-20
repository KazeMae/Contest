/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime 2023-07-18 15:23:49
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1000005; // 1e6 + 5

string S[N];

// int get_min(string str) {
//     int n = str.size();
//     int i = 0, j = 1;
//     while (i < n && j < n) {
//         int k = 0;
//         while (k < n && str[i + k] == str[j + k]) k++;
//         if (k == n) break;
//         if (str[i + k] > str[j + k]) i += k + 1;
//         else j += k + 1;
//         if (i == j) i++;
//     }
//     int res = min(i, j);
//     str[res + n] = 0;
//     return res;
// }
string get_min(string s) //最小表示法 获得s的最小循环同构 0开头
{
    int n = s.size();
    int i = 0, j = 1, k = 0;
    while (i < n && j < n && k < n)
    {
        int t = s[(i + k) % n] - s[(j + k) % n];
        if (!t) k ++;
        else
        {
            if (t > 0) i += k + 1;
            else j += k + 1;
            if (i == j) i ++;
            k = 0;
        }
    }
    int idx = min(i, j);//首字母下标
    string son = s.substr(idx) + s.substr(0, idx);
    return son;
}

void solve() {
    int n, m;
    cin>> n >> m;
    for(int i = 0 ; i < n; i++) {
        cin>> S[i];
        S[i] = get_min(S[i]);
    }
    int q;
    cin>> q;
    while(q --) {
        int x, y;
        cin>> x >> y;
        cout<< (S[x - 1] == S[y - 1] ? "Yes" : "No") <<endl;
    }
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
