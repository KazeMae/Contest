#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5;
long long ch[N];
struct t
{
    int lson, rson;
    long long value;
    long long tag;
}tree[2 * N];
int tot = 0, add;
void push_up(int root) { tree[root].value = tree[tree[root].lson].value + tree[tree[root].rson].value; }
void bulid(int& root, int L, int R)
{
    if (!root)root = ++tot;
    if (L == R) { tree[root].value = ch[L]; return; }
    int mid = (L + R) / 2;

    bulid(tree[root].lson, L, mid);
    bulid(tree[root].rson, mid + 1, R);
    push_up(root);
}
void push_tag(int root, int L, int R, int k)
{
    tree[root].value += (R - L + 1) * k;
    tree[root].tag += k;
}
void push_down(int root, int L, int R)
{
    int mid = (L + R) / 2;
    push_tag(tree[root].lson, L, mid, tree[root].tag);
    push_tag(tree[root].rson, mid + 1, R, tree[root].tag);
    tree[root].tag = 0;
    return;
}
void update(int root, int l, int r, int L, int R)
{
    if (!root)root = ++tot;
    if (l <= L && r >= R) { push_tag(root, L, R, add); return; }
    int mid = (L + R) / 2;

    if(tree[root].tag)push_down(root, L ,R);
    if (l <= mid)update(tree[root].lson, l, r, L, mid);
    if (r > mid)update(tree[root].rson, l, r, mid + 1, R);
    push_up(root);
}
long long query(int root, int l, int r, int L, int R)
{
    long long ans = 0;
    if (l <= L && r >= R)return tree[root].value;
    int mid = (L + R) / 2;
    if(tree[root].tag)push_down(root, L, R);

    if (l <= mid)ans += query(tree[root].lson, l, r, L, mid);
    if (r > mid)ans += query(tree[root].rson, l, r, mid + 1, R);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    int n, m, root = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)cin >> ch[i];
    bulid(root, 1, n);
    while (m--)
    {
        //char op;
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)cin >> add, update(1, x, y, 1, n);
        else
        {
            long long ans = query(1, x, y, 1, n);
            cout << ans << endl;
        }
    }
    return 0;
}
