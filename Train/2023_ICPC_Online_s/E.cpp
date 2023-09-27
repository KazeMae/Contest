#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long
const int N = 1e5 + 5;

int f[N];
int ff[N];
int fsum[N];

vector<int> b[N];
int arr[N];
queue<int>qq;


void solve() {
    int n, m;
    cin>> n >> m;
    vector<int> p(n);
    for(int i = 0; i <= n; ++ i) {
        f[i] = i;

    }
    for(int i = 1; i < n; ++ i) {
        cin>> p[i];
        f[i+1] = p[i];
    }
    for(int i = 0; i < m; ++ i) {
        int u, v;
        cin>> u >> v; 
        b[v].push_back(u);
        b[u].push_back(v);
        fsum[v] = 1;
        fsum[u] = 1;
    }
    qq.push(1);
    while(!qq.empty())
    {
        int y = qq.front();
        ff[y] = 1;
        int ret = arr[y] + 1;
        qq.pop();
        for(int i = 0;i < b[y].size();++i)
        {
            int xx = b[y][i];
            if(ff[xx] == 0)
            {
                qq.push(xx);
                ff[xx] = 1;
            }
            while(arr[xx] == 0 && xx != 1 || xx != 1 && arr[xx] > ret)
            {
                arr[xx] = ret;
                if(fsum[xx] == 1 && ff[xx] == 0)
                {
                    qq.push(xx);
                    ff[xx] = 1;
                }
                xx = f[xx];

            }
        }


    }
    for(int i = 2;i <= n;++i)
    {
        if(arr[i] == 0)
        {
            cout<<-1<<' ';
        }
        else
        {
            cout<<arr[i]<<' ';
        }

    }
    cout<<endl;
}

signed main() {
     std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int t; cin>> t; while(t --)
        solve();
}
