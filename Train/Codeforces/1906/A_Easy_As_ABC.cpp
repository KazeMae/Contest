#include<bits/stdc++.h>
#define endl '\n'
#define int long long


using namespace std;

int n,m,k;
int t;
vector<string>v;
int arrx[8] = {0,1,0,-1,-1,1,1,-1};//下,右,上,左,左上,右下,
int arry[8] = {1,0,-1,0,-1,1,-1,1};
string ans;
int book[5][5];
void Dfs(int x,int y,string ret,int kt,int h)
{
    if(kt == 3)
    {
        if(ans.size() == 0)
        {
            ans = ret;
        }
        else
        {
            ans = min(ans,ret);
        }
        return ;
    }
    for(int i = 0;i < 8;++i)
    {
        int xx = x + arrx[i];
        int yy = y + arry[i];
        if(xx>= 0 && xx < 3 && yy >= 0 && yy < 3 && h != i)
        {
            int ktt;
            if(i == 0)
            {
                ktt = 2;
            }
            else if(i == 1)
            {
                ktt = 3;
            }
            else if(i == 2)
            {
                ktt = 0;
            }
            else if(i == 3)
            {
                ktt = 1;
            }
            else if(i == 4)
            {
                ktt = 5;
            }
            else if(i == 5)
            {
                ktt = 4;
            }
            else if(i == 6)
            {
                ktt = 7;
            }
            else if(i == 7)
            {
                ktt = 6;
            }

            Dfs(x+arrx[i],y + arry[i],ret + v[x+arrx[i]][y + arry[i]],kt+1,ktt);
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);
    string s;
    for(int i =0;i < 3;++i)
    {
        cin>>s;
        v.push_back(s);
    }
    for(int i =0;i < 3;++i)
    {
        for(int j = 0;j < 3;++j)
        {
            string kret = v[i];
            string kt;
            kt += kret[j];
            Dfs(i,j,kt,1,-1);   
        }
    }

    cout<<ans<<endl;
    
    




    

    return 0;
}
