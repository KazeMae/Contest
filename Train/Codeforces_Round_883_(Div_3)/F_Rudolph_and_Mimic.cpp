/*******************************
  | Author:  KAZE_mae
  | Website: https://cloudfall.top
  | Problem: F. Rudolph and Mimic
  | Contest: Codeforces Round 883 (Div. 3)
  | URL:     https://codeforces.com/contest/1846/problem/F
  | When:    2023-07-09 16:55:38
  |
  | Memory:  256 MB
  | Time:    1000 ms
 *******************************/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
// #define endl "\n"

//#define int long long
const int N = 1000005; // 1e6 + 5

void solve() {
    int n, tag = 0;
    bool flag = true;
    cin>> n;
    map<int, int> tn, tp;
    vector<int> vac(n + 5), res(n + 5), ans;


    for(int i = 1; i <= n; i++) {
        cin>> vac[i], tn[vac[i]] ++ ;
    }

    // 第一次查询
    cout<< "- 0 " <<endl;
    for(int i = 1; i <= n; i++) {
        cin>> res[i], tp[res[i]] ++ ;
    }

    // 判断是否变化
    for(int i = 1; i <= 9; i++) {
        if(tn[i] < tp[i]) {
            tag = i;
            flag = false;
            break;
        }
    }

    //如果第一次没变， 查询第二次
    if(flag) {
        //初始化 tp， 读入第二次
        tp.clear();
        cout<< "- 0 " <<endl;
        for(int i = 1; i <= n; i++) {
            cin>> res[i], tp[res[i]] ++ ;
        }

        // 判断是否变化
        for(int i = 1; i <= 9; i++) {
            if(tn[i] < tp[i]) {
                tag = i;
                flag = false;
                break;
            }
        }
    }

    vac.clear(), tn.clear();
    // 删除肯定不是伪装者的位置
    for(int i = 1; i <= n; i++) {
        if(res[i] != tag) {
            ans.push_back(i);
        }else {
            vac.push_back(res[i]);
            tn[res[i]] ++;
        }
    }
    cout<< "- " << ans.size();
    for(auto i:ans) cout<< " " << i;
    cout<<endl;

    n -= ans.size();

    // 第二段查询
    res.resize(n + 5), tp.clear();
    tag = 0, flag = false;

    // 查询
    for(int i = 1; i <= n; i++) {
        cin>> res[i], tp[res[i]] ++ ;
    }

    for(int i = 1; i <= 9; i++) {
        if(tn[i] < tp[i]) {
            tag = i;
            flag = true;
            break;
        }
    }

    if(flag) {
        for(int i = 1; i <= n; i++) {
            if(res[i] == tag) {
                cout<< "! " << i <<endl;
                return;
            }
        }
        cout<< "! 1" <<endl;
    }else {
        tp.clear();
        cout<< "- 0 " <<endl;
        for(int i = 1; i <= n; i++) {
            cin>> res[i], tp[res[i]] ++ ;
        }

        for(int i = 1; i <= 9; i++) {
            if(tn[i] < tp[i]) {
                tag = i;
                flag = true;
                break;
            }
        }

        for(int i = 1; i <= n; i++) {
            if(res[i] == tag) {
                cout<< "! " << i <<endl;
                return;
            }
        }
        cout<< "! 1" <<endl;
    }

}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
