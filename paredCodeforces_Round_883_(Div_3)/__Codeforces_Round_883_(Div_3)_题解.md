# Codeforces_Round_883_(Div_3)

**[1846](https://codeforces.com/contest/1846)**

## A. Rudolph and Cut the Rope

### Solution:

找出 **$a$** 大于 **$b$ ** 的组数即为答案

### Code

```c++
/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: A. Rudolph and Cut the Rope 
| Contest: Codeforces Round 883 (Div. 3)
| URL:     https://codeforces.com/contest/1846/problem/A
| When:    2023-07-09 12:30:24
| 
| Memory:  256 MB
| Time:    2000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

//#define int long long
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, a, b, ans = 0;
    cin>> n;
    for(int i = 0; i < n; i++) {
        cin>> a >> b;
        if(b < a) ans ++;
    }
    cout<< ans <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}

```



## B. Rudolph and Tic-Tac-Toe

### Solution

暴力枚举每种情况即可

### Code

```c++
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

```



## C. Rudolf and the Another Competition

### Solution

对鲁道夫预测解题时间排序，从小到大计算**罚时**（每道题在过题时候所花的时间）。再对每个人进行同样计算，计算完和鲁道夫的结果比较，如果过题数大于鲁道夫的，或者过题数相等罚时小于鲁道夫，则答案 +1

**注意数据范围**

### Code

```c++
/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: C. Rudolf and the Another Competition
| Contest: Codeforces Round 883 (Div. 3)
| URL:     https://codeforces.com/contest/1846/problem/C
| When:    2023-07-09 12:30:26
|
| Memory:  256 MB
| Time:    1000 ms
*******************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

#define int long long
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, m, h, res = 0;
    cin>> n >> m >> h;
    pair<int, int> r;
    std::vector<int> t;
    for(int i = 1; i <= n; i++) {
        t.clear();
        for(int j = 0; j < m; j++) {
            int k;
            cin>> k;
            t.push_back(k);
        }
        sort(t.begin(), t.end());
        int ttk = 0, sle = 0, te = 0;
        for(auto l:t) {
            ttk += te + l, te += l, sle ++;
            if(te > h)
                ttk -= te, sle --;
        }
        // cout<< sle << " " << ttk << " " << te <<endl;
        if(i == 1) r = {sle, ttk}, res ++;
        else if(sle > r.first || (sle == r.first && ttk < r.second)) res ++;
    }
    cout<< res <<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}

```

