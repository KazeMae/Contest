#include<bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int N=2e5+10;
const int mod=998244353;
int a[N],b[N],f[N];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    int cnt=1000000;
    if(n>=1000)
    {
    while(cnt--)
    {
        for(int i=1;i<=n;i+=500)
        {
            f[i]=abs(b[i]-a[i]);
            a[i]=b[i];
            b[i]=f[i];
        }
        int flag=0;
        for(int i=1;i<=n;i+=500)
        {
            if(a[i]!=0)
            {
                flag=1;
            }
        }
        if(!flag)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
else{
    cnt=5000;
    while(cnt--)
    {
        for(int i=1;i<=n;i++)
        {
            f[i]=abs(b[i]-a[i]);
            a[i]=b[i];
            b[i]=f[i];
        }
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=0)
            {
                flag=1;
            }
        }
        if(!flag)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
}
signed main()
{
//  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
