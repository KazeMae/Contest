#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long
const int N=5e5+10;
int arr[N];
double p[N];
double cnt[N];
void solve() {
    cout<< setiosflags(ios::fixed) << setprecision(10);
    int n;
    cin>>n;
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
    }
    double ans=n;
    for(int i=1;i<=n;i++)
    {
        double k=p[i]*(1.0)/100000;
        double s=i-arr[i]+cnt[i-1]-cnt[arr[i]];
        if(s<0)s=0;
        double x=(i-n)*k+(s)*(1-k);
        if(x<0)ans+=x;
        cnt[i]=ans;
    }
    cout<<ans<<endl;
}

signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
