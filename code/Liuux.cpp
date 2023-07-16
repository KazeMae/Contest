/**
 * @Author KAZE_mae
 * @Website cloudfall.top
 * @DateTime
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define endl "\n"

#define int long long
const int N = 1000005; // 1e6 + 5
pair<char, int> s[N];
void solve() {
    string ss;
    int ls;
    cin>> ls >> ss;
    for(int i = 0; i < ls; i++) {
        s[i].first = ss[i], s[i].second = i;
        // cout<< s[i].second << " " << s[i].first <<endl;
    }
    stack<pair<char, int>> p;
    for(int i = 0;i < ls; i ++)
    {
        if(s[i].first=='(')
            p.push(s[i]);
        else
            if(p.empty()) p.push(s[i]);
            else if(s[i].first ==')'&& p.top().first =='(') p.pop();
            else p.push(s[i]);
    }
    vector<int> l, r;
    while(!p.empty()) {
        if(p.top().first == '(') l.push_back(p.top().second);
        else r.push_back(p.top().second);
        p.pop();
    }

    /*for(auto i:l) {
        cout<< i <<" ^";
    }
    cout<<endl;
    for(auto i:r) {
        cout<< i <<" *";
    }
    cout<<endl;*/

    if(l.size() != r.size()) cout<< -1 <<endl;
    else {
        int ans = 0;
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        for(int i = 0; i < l.size(); i++) {
            ans += abs(l[i] - r[l.size() - i - 1]);
        }
        cout<< ans <<endl;
    }
}
signed main () {
    // std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t; cin>> t; while(t --)
        solve();
}
