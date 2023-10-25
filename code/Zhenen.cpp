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

signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.insert(50);
    cout<< *(s.find(2) ++ ) << " " << *(s.end()) <<endl;
}
