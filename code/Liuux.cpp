#include<bits/stdc++.h>
#define int long long 
//#define endl '\n'
#define lowbit(x) x&(-x)
using namespace std;

const int N=1e6+10;
typedef pair<int,int>PII;
int a[N],f[N];

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)a[i]=i;
            set<int>s;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n;j++)a[j]=j;
        do{
            int ans=0,flag=1;
            for(int j=1;j<=i;j++)
            {
                ans+=a[j];
            }
            for(int j=i+1;j<=n;j++)
            {
                if(abs(a[j]-a[j-i])%2==1)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)s.insert(i);
//            if(flag&&i==3)
//            {
//                for(int j=1;j<=n;j++)cout<<a[j]<<" ";
//                cout<<endl;
//            }
        }while(next_permutation(a+1,a+1+n));
    }
    for(auto i:s)cout<<i<<" ";
    cout<<endl;
}
signed main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}
