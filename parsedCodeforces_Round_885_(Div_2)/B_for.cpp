
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, t, k;
const int N = 2e5 + 10;
int arr[N];
vector<int>v[N];
signed main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int ans = 1e9;
        for (int i = 1; i <= n; i++)
        {
            v[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            if (!v[arr[i]].size()) v[i].push_back(0);
            v[arr[i]].push_back(i);
        }
        for (int i = 1; i <= k; i++)
        {
            priority_queue<int> q;
            v[i].push_back(n + 1);
            int len = v[i].size();
            for (int j = 1; j < len; j++)
            {
                q.push(v[i][j] - v[i][j - 1] - 1);
            }
            if (q.empty()) continue;
            int x = q.top(); q.pop();
            q.push(x / 2);
            ans = min(ans, q.top());
        }
        cout << ans << endl;
    }
    return 0;
}
