#include<bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;
const int N = 1e6 + 10;
const int mod = 998244353;
typedef pair<int, int>PII;
queue<int>q;



struct TRIE {
    struct node {
        int son[26], fail, flag = 0;
    } trie[N];
    int idx = 1;

    void ins(string s) {
        int u = 1, len = s.size();
        for (int i = 0; i < len; i++)
        {
            int v = s[i] - 'a';
            if (!trie[u].son[v])trie[u].son[v] = ++idx;
            u = trie[u].son[v];
        }
        trie[u].flag++;
    }

    void getfail() {
        for (int i = 0; i < 26; i++)trie[0].son[i] = 1;
        q.push(1);
        trie[1].fail = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 26; i++)
            {
                int v = trie[u].son[i];
                int Fail = trie[u].fail;
                if (!v)
                {
                    trie[u].son[i] = trie[Fail].son[i];
                    continue;
                }
                trie[v].fail = trie[Fail].son[i];
                q.push(v);
            }
        }
    }

    int query(string s) {
        int u = 1, ans = 0, len = s.size();
        for (int i = 0; i < len; i++)
        {
            int v = s[i] - 'a';
            int k = trie[u].son[v];
            while (k > 1 && trie[k].flag != -1)
            {
                ans += trie[k].flag;
                trie[k].flag = -1;
                k = trie[k].fail;
            }
            u = trie[u].son[v];
        }
        return ans;
    }
};

void solve()
{
    TRIE t;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        t.ins(s);
    }
    t.getfail();
    string s;
    cin >> s;
    int ans = t.query(s);
    cout << ans << endl;
}
signed main()
{
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
//  cin>>t;
    while (t--)solve();
    return 0;
}
