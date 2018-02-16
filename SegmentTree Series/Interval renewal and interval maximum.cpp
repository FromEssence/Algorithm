///CF_272C Dima and Staircase
#include <bits/stdc++.h>
using namespace std;

#define lson l, m, rt << 1
#define rson m+1, r, rt<<1 | 1
#define LL long long
const LL maxn=1e5+20;
LL mark[maxn<<2];
LL MaxVal[maxn<<2];
void PushUp(LL rt){
	MaxVal[rt] = max(MaxVal[rt<<1],MaxVal[rt<<1|1]);
}

void PushDown(LL rt, LL m){ //m是结点rt表示的区间长度
	if(mark[rt]){
		mark[rt<<1] = mark[rt]; //标记传给左儿子
		mark[rt<<1|1] = mark[rt]; //标记传给右儿子
		MaxVal[rt<<1] = mark[rt];//左儿子根据自身区间长度，累加标记
		MaxVal[rt<<1|1] = mark[rt];
		mark[rt]=0; //取消此节点的标记
	}
}

void build(LL l, LL r, LL rt){
	mark[rt]=0;
	if(l==r){
		cin>>MaxVal[rt];
		return;
	}
	LL m=(l+r)>>1;
	build(lson);
	build(rson);
	PushUp(rt);
}

void update(LL L,LL R,LL c,LL l,LL r,LL rt){
	//[L,R]是更新的区间，[l,r]是节点rt表示的区间
	if(L<=l && r<=R){
		mark[rt] = c;
		MaxVal[rt] = (LL)c;
		return ;
	}
	PushDown(rt, r-l+1);
	LL m=(l+r)>>1;
	if(L <= m) update(L, R, c, lson);
	if(R > m)  update(L, R, c, rson);
	PushUp(rt);
}

LL query(LL L,LL R,LL l,LL r,LL rt){
	if(L<=l && r<=R) return MaxVal[rt];
	PushDown(rt, r-l+1);
	LL m=(l+r)>>1;
	LL ret =0;
	if(L<=m) ret = max(ret, query(L, R, lson));
	if(m<R) ret = max(ret, query(L, R, rson));
	return ret;
}

int main(){
    ios::sync_with_stdio(false);
	int n, m;
	cin >>n;
	build(1, n, 1);
	LL w, h;
	cin >>m;
	for(int i=0; i<m; i++){
		cin >>w >>h;
		LL mx=query(1, w, 1, n, 1);
		cout <<mx <<'\n';
		update(1, w, mx+h, 1, n, 1);
	}

	return 0;
}
