/*
 * HDU 2966 In case of failure
 * read until EOF
 */

#include <bits/stdc++.h>
using namespace std;
const int N=5e4+10,maxdim=5;
const long long inf=1e16;
const long double eps=1e-14;

#define ll long long
#define ls (rt<<1)
#define rs (rt<<1|1)

#define sqr(x) 1ll*(x)*(x)

inline int read(){
    int x(0),f(1);
    char ch=getchar();
    while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int k,n,idx,top_num;   //k为维数,n为点数
struct point {
    int x[maxdim];
    bool operator < (const point &u) const {
        return x[idx]<u.x[idx];
    }
} po[N];

typedef pair<ll,point>tp;
priority_queue<tp>Q;// m个内部，距离较大放队首，要弹出

struct kdTree {
    point pt[N<<2];

    int son[N<<2];

    void build(int l,int r,int rt=1,int dep=0) {
        if(l>r)
            return;
        son[rt]=r-l;
        son[ls]=son[rs]=-1;
        idx=dep%k;
        int mid=(l+r)/2;
        // 第idx维作为标准隔开
        nth_element(po+l,po+mid,po+r+1);
        pt[rt]=po[mid];
        build(l,mid-1,ls,dep+1);
        build(mid+1,r,rs,dep+1);
    }
    void query(point p,int m,int rt=1,int dep=0) {
        if(son[rt]==-1)
            return;

        tp nd(0,pt[rt]);// 距离
        for(int i=0; i<k; i++)
            nd.first += sqr((pt[rt].x[i]-p.x[i]));

        int dim=dep%k,x=ls,y=rs,fg=0;
        if(p.x[dim]>=pt[rt].x[dim])
            swap(x,y);
        // 查询对应的半空间
        if(~son[x])
            query(p,m,x,dep+1);

        if(Q.size()<top_num){
            Q.push(nd);
            fg = 1;
        }
        else{
            if(nd.first<Q.top().first)
                Q.pop(), Q.push(nd);
            ll dis_here = sqr((p.x[dim]-pt[rt].x[dim]));
            if(dis_here<Q.top().first)
                fg = 1;
        }

        if(~son[y]&&fg)
            query(p,m,y,dep+1);
    }
} kd;

void print(point &p) {
    for(int j=0; j<k-1; j++)
        printf("%d ", p.x[j]);
    printf("%d\n", p.x[k-1]);
}

int main() {

    while(scanf("%d%d", &n, &k)!=EOF){
        int query_num;
        for(int i=1; i<=n; i++){
            for(int j=0; j<k; j++){
                scanf("%d", &po[i].x[j]);
            }
        }

        kd.build(1,n);

        query_num = read();
        for(int mm=query_num; mm>0; mm--) {
            point ask;
            for(int j=0; j<k; j++){
                scanf("%d",&ask.x[j]);
            }

            scanf("%d", &top_num);
            kd.query(ask,top_num);

            printf("the closest %d points are:\n", top_num);
            point ans[12];
            int cnt = 0;
            while(!Q.empty()){
                ans[cnt++] = Q.top().second;
                Q.pop();
            }
            for(int i=top_num-1; i>=0; i--){
                print(ans[i]);
            }

        }
    }

    return 0;
}
