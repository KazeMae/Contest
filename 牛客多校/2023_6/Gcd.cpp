/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         
 * @DateTime    
 */
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
//#define int long long

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1000005; // 1e6 + 5

void solve() {
    int x, y, z;
    cin>>x>>y>>z;
    int k=__gcd(x,y);
    if(z==x||z==y)
    {
        cout<<"YES"<<endl;
        return;
    }
    if(!z)
    {
        cout<<"YES"<<endl;
        return;
    }
    if(!x||!y)
    {
        if(x&&z%x==0)cout<<"YES"<<endl;
        else if(y&&z%y==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    if(k==0)
    {
        if(!z)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }
    if(z%k==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
signed main () {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin>> t; while(t --)
        solve();
}
