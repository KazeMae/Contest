#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long


int t;
string s;

int Judge(int l,int r)
{
    while(s[l] == s[r] && l <= r)
    {
        l++;
        r--;
    }
    if(l <= r)
    {
        return 0;
    }
    return 1;

}
signed main() {
    cin>>t;
    while(t--)
    {
        
        cin>>s;
        int sum = 0;
        for(int len = 1;len <= s.size()/2;++len)
        {
            for(int i = 0;i + len < s.size();++i)
            {
                if((1 + len)% 2 == 0)
                {
                    sum += Judge(i,i+len);
                }
                if(i + 1+ len +len < s.size())
                {
                    
                }
            }
        }
    }
}
