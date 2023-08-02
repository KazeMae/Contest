/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         
 * @DateTime    2023-07-26 02:28:45
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin>> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin>> a[i] >> b[i];
    }
    deque<PII> q;
    for(int i = 0; i < n; i++) {
        while(!q.empty() && q.front().first <= b[i]) q.pop_front();
        q.push_front({b[i], a[i]});
        cout<< q.back().first <<endl;
        while(!q.empty() && q.back().second == i + 1) q.pop_back();
    }
}
