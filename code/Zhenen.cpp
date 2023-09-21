#define db double
const db PI=acos(-1);
void solve(){
    cout<<setiosflags(ios::fixed)<<setprecision(10);
    db x1,y1,r1;
    db x2,y2,r2;
    db u,v,x,y;
    cin>>u>>v>>x>>y;
    x1=(u+x)/2;y1=(v+y)/2;
    r1=sqrtl((u-x)*(u-x)+(v-y)*(v-y))/2;
    
    cin>>u>>v>>x>>y;
    x2=(u+x)/2;y2=(v+y)/2;
    r2=sqrtl((u-x)*(u-x)+(v-y)*(v-y))/2;

    db l,r;
    if(x2>x1&&y2>y1){
        l=PI,r=3*PI/2;
    } else if(x2<x1&&y2>y1){
        l=3*PI/2;r=2*PI;
    } else if(x2>x1&&y2<y1){
        l=PI/2,r=PI;
    } else {
        l=0,r=PI/2;
    }

    auto get=[&](db c){
        db x3=x2+r2*cos(c),y3=y2+r2*sin(c);
        return abs(x3-x1)+abs(y3-y1);
    };
    while(abs(r-l)>eps){
        db ml=l+(r-l)/3;
        db mr=r-(r-l)/3;
        if(get(ml)<get(mr)) r=mr;
        else l=ml;
    }   
    cout<<get(r)<<'\n';

    //直接算
    //db d=abs(x1-x2)+abs(y1-y2)-sqrtl(2)*r2;
    //cout<<d<<'\n';
}
