#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define abs(x) (x < 0 ? -x : x)


signed main() {
    int n, m;
    cin>> n >> m;
    vector<string>v1,v2;
    map<string,int>mm1,mm2;
    string s;
    for(int i =0 ;i < n;++i)
    {
        cin>>s;
        if(mm1[s] == 0)
        {
            mm1[s] = 1;
            v1.push_back(s);
        }
    }
    for(int i =0 ;i < m;++i)
    {
        cin>>s;
        if(mm2[s] == 0)
        {
            mm2[s] = 1;
            v2.push_back(s);
        }
    }
    map<string,int>mm;
    int l = 0;
    int r = 0;
    while(l < v1.size() && r < v2.size())
    {
        if(mm[v1[l]] == 0)
        {
            mm[v1[l]] = 1;
            cout<<v1[l]<<endl;
        }
        l++;
        if(mm[v2[r]] == 0)
        {
            mm[v2[r]] = 1;
            cout<<v2[r]<<endl;
        }
        r++;
    }
    while(l < v1.size())
    {
        if(mm[v1[l]] == 0)
        {
            mm[v1[l]] = 1;
            cout<<v1[l]<<endl;
        }
        l++;
    }
    while(r < v2.size())
    {
        if(mm[v2[r]] == 0)
        {
            mm[v2[r]] = 1;
            cout<<v2[r]<<endl;
        }
        r++;
    }

}
