#include<bits/stdc++.h>
#define endl '\n'
#define int long long


using namespace std;

int n,m,k;
int t;

signed main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    vector<int>v;
    int a;
    cin>>n;
    int sum = 0;
    int ret = 0;
    for(int i = 0;i < n;++i)
    {
        cin>>a;
        v.push_back(a);
        sum += a;
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i = 0;i < n - 1;++i)
    {
        ret += v[i];
        if(ret*2 <= sum - ret)
        {
            ans = ret;
        }
        else
        {
            ret -= v[i];
            int l = 0;
            int r = v[i];
            while(l < r)
            {
                int mid = l + r + 1>> 1;
                int kret = ret + mid;
                if(kret*2 <= sum - kret)
                {
                    l = mid;
                }
                else
                {
                    r = mid - 1;
                }
            }
            ans = ret + l;
            break;
        }
    }
    

    cout<<ans<<endl;


    

    return 0;
}
