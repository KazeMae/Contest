#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define abs(x) (x < 0 ? -x : x)
#define int long long
const int N=1e6+10;
int p[N];
int n,m;
int find(int x)
{
    if(p[x]!=x)p[x]=find(p[x]);
    return p[x];
}
int edge[N];
int node[N];
signed main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        node[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        int x=find(u),y=find(v);
        if(x==y)
        {
            edge[x]++;
            continue;
        }
        p[y]=x;
        node[x]+=node[y];
        edge[x]+=(edge[y]+1);
    }
    int sum=0;
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        p[i]=find(p[i]);
        int x=p[i];
        if(x==i)
        {
            sum+=((node[x]*(node[x]-1)/2)-edge[x]);
            v.push_back(node[x]);
        }
    }
    sort(v.begin(), v.end());
    if(sum!=0)
    {
        cout<<sum<<endl;
    }
    else
    {
        cout<<sum+v[0]*v[1]<<endl;
    }
}
