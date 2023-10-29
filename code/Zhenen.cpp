#include <bits/stdc++.h>
#include <string.h>

using namespace std;
#define int long long
typedef pair<int, int> PII;
#define fr(i, a, n) for(int i = a; i <= n; i ++)
const int N = 100000 + 5;
int a, b, c, d, e, ans, n;
int q[N];
__int128 p[N];

struct node
{
    __int128 a;
    int b, c;
}str[N];

int cmp(node x, node y)
{
    if(x.b != y.b) return x.b < y.b;
    else return x.a < y.a;
}

inline void print(__int128 x)
{
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

void solve()
{
    cin >> n;
    fr(i, 1, n)
{
    __int128 sum = 0;
    cin >> a >> b >> c >> d >> e;
    sum += 3 * a + 2 * b + c;
    ans = c + d + e;
    if(ans == 0)
    {
        sum += 1145141919810114514;
    }
    sum -= ans * 5;
    if(sum < 0) sum = 0;
    str[i].a = sum;
    str[i].b = ans;
    str[i].c = i;
}
    sort(str + 1, str + 1 + n, cmp);
    int idx = 0;
    str[0].a = -1;
    fr(i, 1, n)
{
    //      print(str[i].a);
    //      cout << ' ' << str[i].b << ' ' << str[i].c << endl;
    p[str[i].c] = str[i].a;
    if(str[i - 1].b != str[i].b || str[i - 1].a != str[i].a)
    {
        //          cout << 'y';
        q[str[i].c] = ++ idx;
    }else
    {
        q[str[i].c] = idx;
    }
}
    fr(i, 1, n)
{
    print(str[q[i]].a);
    cout << ' ' << q[i] << endl;
}
}

signed main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0),cout.tie(0);
    //  cin >> T;
    //  while(T -- )
    solve();
    return 0;
} 
