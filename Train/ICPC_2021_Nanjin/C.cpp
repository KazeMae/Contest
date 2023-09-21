#include<bits/stdc++.h>
using namespace std;
#define max(a, b) ((a) > (b) ? (a) : (b))

signed main()
{
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    vector<int> v(1000005), mm1(5000015), mm2(5000015), m_max(5000015);
    cin>> n >> m;
    int mmax = 0;
    for (int i = 0; i < n; ++ i)
    {
        cin>> v[i];
        v[i] += 2000005;
        ++ mm1[v[i]];
        mmax = max(mmax, mm1[v[i]]);
    }

    if (m == 0) cout<< mmax;
    else {
        for (int i = n - 1; i >= 0; --i)
        {
            mm2[v[i]] = max(0, mm2[v[i]] - 1);
            ++ mm2[v[i] + m];
            m_max[v[i] + m] = max(m_max[v[i] + m], mm2[v[i] + m]);
        }
        for (auto x : v) {
            mmax = max(mmax, mm1[x] + m_max[x]);
        }
        cout<< mmax;
    }
    return 0;
}
