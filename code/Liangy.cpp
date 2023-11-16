#include <stdio.h>
#include <string.h>
const int M=300005;
struct treeNode{int l,r,sum,lazy;}t[M*50];
int root=1,cnt=1;
void push_down(int now,int tl,int tr) {
    if (t[now].lazy==-1) return ;
    if (!t[now].l) t[t[now].l=++cnt]=(treeNode){0,0,0,-1};
    if (!t[now].r) t[t[now].r=++cnt]=(treeNode){0,0,0,-1};
    int mid=(tl+tr)>>1;
    t[t[now].l].lazy=t[t[now].r].lazy=t[now].lazy;
    t[t[now].l].sum=(mid-tl+1)*t[now].lazy;
    t[t[now].r].sum=(tr-mid)*t[now].lazy;
    t[now].lazy=-1;
}
void modify(int &now,int tl,int tr,int l,int r,int v) {
    if (!now) t[now=++cnt]=(treeNode){0,0,0,-1};
    if (tl==l&&tr==r) {
        t[now].sum=(r-l+1)*v;
        t[now].lazy=v;
        return ;
    }
    push_down(now,tl,tr);
    int mid=(tl+tr)>>1;
    if (r<=mid) modify(t[now].l,tl,mid,l,r,v);
    else if (l>mid) modify(t[now].r,mid+1,tr,l,r,v);
    else {
        modify(t[now].l,tl,mid,l,mid,v);
        modify(t[now].r,mid+1,tr,mid+1,r,v);
    }
    t[now].sum=t[t[now].l].sum+t[t[now].r].sum;
}
int query(int now,int tl,int tr,int l,int r) {
    if (!now) return 0;
    if (tl==l&&tr==r) return t[now].sum;
    push_down(now,tl,tr);
    int mid=(tl+tr)>>1;
    if (r<=mid) return query(t[now].l,tl,mid,l,r);
    else if (l>mid) return query(t[now].r,mid+1,tr,l,r);
    else return query(t[now].l,tl,mid,l,mid)+query(t[now].r,mid+1,tr,mid+1,r);
}
int main(void) {
    int n,m; scanf("%d%d",&n,&m);
    t[root].sum=n; t[root].lazy=1;
    while (m--) {
        int l,r,k; scanf("%d%d%d",&l,&r,&k);
        if (k==1) {
            modify(root,1,n,l,r,k-1);
        } else if (k==2) {
            modify(root,1,n,l,r,k-1);
        }
        printf("%d\n", query(root,1,n,1,n));
    }
    return 0;
}
