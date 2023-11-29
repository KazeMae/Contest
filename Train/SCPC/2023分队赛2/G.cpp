#include<bits/stdc++.h>
using namespace std;

const int N = 10000;

struct autoAC {
    struct Tire {
        int fail = 0;
        int vis[30];
        int cnt[30];
        int end = 0;
    };

    int tot = 0;
    vector<Tire> AC;
    autoAC() : AC(N) {}

    void build(string s) {
        int len = s.size();
        int p = 0;
        for(int i = 0; i < len; ++ i) {
            if(AC[p].vis[s[i] - 'a'] == 0) AC[p].vis[s[i] - 'a'] = ++ tot;
            ++ AC[p].cnt[s[i] - 'a'];
            p = AC[p].vis[s[i] - 'a'];
        }
        ++ AC[p].end;
    }

    void getfail() {
        queue<int> q;
        for(int i = 0; i < 26; ++ i)
            if(AC[0].vis[i] != 0)
                AC[AC[0].vis[i]].fail = 0, q.push(AC[0].vis[i]);

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i = 0; i < 26; ++ i) {
                if(AC[u].vis[i] != 0) {
                    AC[AC[u].vis[i]].fail = AC[AC[u].fail].vis[i];
                    q.push(AC[u].vis[i]);
                }else AC[u].vis[i] = AC[AC[u].fail].vis[i];
            }
        }
    }

    int query(string s) {
        int len = s.size();
        int p = 0, ans = 0;
        for(int i = 0; i < len; ++ i) {
            p = AC[p].vis[s[i] - 'a'];
            for(int k = p; k && AC[k].end != -1; k = AC[k].fail) {
                ans += AC[k].end;
                AC[k].end = -1;
            }
        }
        return ans;
    }

};


signed main() {
    // autoAC ac;
    int n;
    cin>> n;
    vector<string> sl(n);
    map<string, int> mp;
    for(int i = 0; i < n; ++ i) {
        cin>> sl[i];
        // ac.build(sl[i]);
        for(int k = 1; k <= sl[i].size(); ++ k) {
            for(int j = 0; j + k <= sl[i].size(); ++ j) {
                mp[sl[i].substr(j, k)] ++;
                // cout << sl[i].substr(j, k) << " ";
            }
        }
        // cout <<endl;
    }

    for(int i = 0; i < n; ++ i) {
        for(int k = 1, flag = 0; k <= sl[i].size(); ++ k) {
            for(int j = 0; j + k <= sl[i].size(); ++ j) {
                string t = sl[i].substr(j, k);
                int cnt = 0;
                for(int q = 0; q < sl[i].size(); ++ q) {
                    int qr = sl[i].find(t, q);
                    if(qr == -1) break;
                    else q = qr, cnt ++;
                }
                if(mp[t] - cnt == 0) {
                    cout << t <<endl; // " " << mp[sl[i].substr(j, k)] << " " << i <<endl;
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
    }
}
