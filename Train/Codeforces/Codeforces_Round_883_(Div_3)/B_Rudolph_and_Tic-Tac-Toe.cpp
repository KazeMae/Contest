/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: B. Rudolph and Tic-Tac-Toe
| Contest: Codeforces Round 883 (Div. 3)
| URL:     https://codeforces.com/contest/1846/problem/B
| When:    2023-07-09 12:30:25
| 
| Memory:  256 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5

char a[5][5];
void solve() {
    int x = 0, i = 0, o = 0;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            cin>> a[i][j];
        }
    }
    map<char, int> mp;
    for(int i = 1; i <= 3; i++) {
            if(a[i][1] == a[i][2] && a[i][1] == a[i][3]) mp[a[i][1]] ++;
    }
    for(int i = 1; i <= 3; i++) {
            if(a[1][i] == a[2][i] && a[1][i] == a[3][i]) mp[a[1][i]] ++;
    }
    if(a[1][1] == a[2][2] && a[1][1] == a[3][3]) mp[a[2][2]] ++;
    if(a[3][1] == a[2][2] && a[1][3] == a[3][1]) mp[a[2][2]] ++;

    if(mp['X'] > 0) x = 1;
    if(mp['O'] > 0) o = 1;
    if(mp['+'] > 0) i = 1;
    // cout<< x << " " << i << " " << o <<endl;
    int ans = 0;
    ans = x + o + i;
    if(ans > 1 || ans == 0) cout<< "DRAW" <<endl;
    else if(x == 1) cout<< "X" <<endl;
    else if(i == 1) cout<< "+" <<endl;
    else if(o == 1) cout<< "O" <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
