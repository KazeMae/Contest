#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,sum;
int a[100005];
bool solve(int x)
{
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
        ans+=a[i]/x;
    }
    return ans>=k;
}
signed main(void)
{
    cin>>n>>k;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    if(sum<k){
        cout<<sum<<endl;
        return 0;
    }
    int l = 1,r = 100000005;
    int mid;
    while(l+1!=r)
    {
        mid = l+r>>1;
        if(solve(mid)) l = mid;
        else r = mid;
    }
    int langfei = 0;
    int count = 0;
    for(int i = 1;i<=n;i++) count+=a[i];
    langfei = count - l*k;
    cout<<langfei;
    return 0;
}
