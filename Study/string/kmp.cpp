#include <bits/stdc++.h>
using namespace std;

const int N = 1000005; // 1e6 + 5

vector<int> kmp(string t) {
    vector<int> nxt(t.size() + 5);
    for(int i = 2, j = 0; i < t.size(); ++ i) {
        while(j && t[j + 1] != t[i]) j = nxt[j];  
        if(t[j + 1] == t[i]) ++ j;
        nxt[i] = j;
    }
    return nxt;
}

void solve();
signed main() {
    string s, t;
    cin>> s >> t;
    s = " " + s;
    t = " " + t;
    auto nxt = kmp(t);

    for(int i = 1, j = 0; i < s.size(); ++ i) {
        while(j && t[j + 1] != s[i]) j = nxt[j];
        if(t[j + 1] == s[i]) ++ j;
        if(j == (int)t.size() - 1) {
            cout << i - ((int)t.size() - 1) + 1 <<endl;
            j = nxt[j];
        }
    }
    for(int i = 1; i < t.size(); ++ i) 
        cout << nxt[i] << " ";
    cout <<endl;
  return 0;
}
