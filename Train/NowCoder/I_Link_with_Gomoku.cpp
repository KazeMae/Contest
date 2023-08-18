/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime 2023-07-21 12:56:41
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5
char mp[1005][1005];
void solve() {
    int n, m;
    cin>> n >> m;
    // map<char, int> gs;
    if(n == 1 && m == 1) {
        cout<< 'x' <<endl;
        return;
    }
    if(m == 1) {
        for(int i = 0; i < n; i++) {
            if(i & 1) cout<< 'o' <<endl;
            else cout<< 'x' <<endl;
        }
        return;
    }
    if(n % 2 == 0) {
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                for(int j = 0; j < m; j++) {
                    if(j % 5) mp[i][j] = 'o';
                    else mp[i][j] = 'x';
                }
            }else {
                for(int j = 0; j < m; j++) {
                    if(j % 5) mp[i][j] = 'x';
                    else mp[i][j] = 'o';
                }
            }
        }
    }else {
        for(int i = 0; i < n - 1; i++) {
            if(i & 1) {
                for(int j = 0; j < m; j++) {
                    if(j % 5) mp[i][j] = 'o';
                    else mp[i][j] = 'x';
                }
            }else {
                for(int j = 0; j < m; j++) {
                    if(j % 5) mp[i][j] = 'x';
                    else mp[i][j] = 'o';
                }
            }
        }
        for(int j = 0; j < m; j++) {
            if(j % 2) mp[n - 1][j] = 'o';
            else mp[n - 1][j] = 'x';
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<< mp[i][j];
        }
        cout<<endl;
    }
    // cout<< gs['x'] << " " << gs['o'] <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
