#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long
map<int,int>mm,m;
map<pair<int,int>,int>mk;


vector<int>v;
set<int>st[1005];

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin>>n;
    int a;
    for(int i = 0;i < n;++i)
    {
        cin>>a;
        v.push_back(a);
    }
    if(n == 1)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    vector<int>vv,vsum;
    vv.push_back(1);
    mm[v[0]] = 1;
    st[v[0]].insert(v[1]);
    if(m[1] == 0)
    {
        m[1] = 1;
        vsum.push_back(1);
    }
    else if(m[2] == 0)
    {
        m[2] = 1;
        vsum.push_back(2);
    }
    for(int i = 0; i < n - 1;++i)
    {
        if(mm[v[i]] == 0 || st[v[i]].find(v[i+1]) == st[v[i]].end())
        {

            mm[v[i]] = 1;
            st[v[i]].insert(v[i+1]);
            mk[{v[i],v[i+1]}] = i+1;
            vv.push_back(i+1);
            if(m[i+1] == 0)
            {
                vsum.push_back(i+1);
            }
            m[i+1]++;
            if(m[i+2] == 0)
            {
                vsum.push_back(i+2);
            }
            m[i+2]++;
        }
        else if(mm[v[i]] != 0 && st[v[i]].find(v[i+1]) != st[v[i]].end())
        {
            if(m[mk[{v[i],v[i+1]}]] > 1)
            {
                m[mk[{v[i],v[i+1]}]]--;
            }
            auto xk = find(vv.begin(),vv.end(),mk[{v[i],v[i+1]}]);
            vv.erase(xk,xk+1);                        ;
            mk[{v[i],v[i+1]}] = i+1;
            vv.push_back(i+1);
            if(m[i+1] == 0)
            {
                vsum.push_back(i+1);
            }
            m[i+1]++;
            if(m[i+2] == 0)
            {
                vsum.push_back(i+2);
            }
            m[i+2]++;
        }
        else if(m[i+1] == 0)
        {
            break;
        }
    }
    if(vsum.size() != n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<vv.size()<<endl;
    for(int i = 0;i < vv.size();++i)
    {
        cout<<vv[i]<<' ';
    }
    cout<<endl;

    return 0;
}
