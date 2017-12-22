/*
[Balkan2007]Mokia
分析：CDQ分治，将查询拆成四个二维前缀和查询，按一维排序，对另一维维护树状数组，类似扫描线 
	  分治[l..r]考虑[l..mid]的修改对[mid+1..r]的影响。注意进行下层递归时要恢复询问的原状 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring> 
using namespace std;
const int MAXW=2000000,MAXQ=10000,MAXM=160000,INF=0x3f3f3f3f;
typedef long long LL;
struct query{
	int id,pos,x,y,type;LL a;
	query(int id,int pos,int x,int y,int type,LL a):id(id),pos(pos),x(x),y(y),type(type),a(a){}
	query(){}
}q[MAXQ+4*MAXM+3];
LL ans[MAXQ+3];
LL c[MAXW+3];
int s,w,Q,qans;
void add(int x,int ad){
	for(;x<=w;x+=(x&-x))c[x]+=ad;
}
LL sum(int x){
	LL ans=0;
	for(;x;x-=(x&-x))ans+=c[x];
	return ans;
}
bool cmp1(query a,query b){
	return a.x<b.x||a.x==b.x&&a.pos<b.pos;
}
bool cmp2(query a,query b){
	return a.pos<b.pos;
}
void solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	sort(q+l,q+r+1,cmp1);
	for(int i=l;i<=r;i++){
		if(q[i].pos>mid&&q[i].type==2)ans[q[i].id]+=q[i].a*sum(q[i].y);
		if(q[i].pos<=mid&&q[i].type==1)add(q[i].y,q[i].a);
	}
	for(int i=l;i<=r;i++)
		if(q[i].pos<=mid&&q[i].type==1)add(q[i].y,-q[i].a);
	sort(q+l,q+r+1,cmp2);
	solve(l,mid);
	solve(mid+1,r);
}
int main(){
	scanf("%d%d",&s,&w);
	int type=0,x1,y1,x2,y2,a;
	for(Q=0,qans=0,scanf("%d",&type);type!=3;scanf("%d",&type)){
		switch(type){
			case 1:
				scanf("%d%d%d",&x1,&y1,&a);++Q;
				q[Q]=query(0,Q,x1,y1,1,a);
				break;
			case 2:
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);++qans;
				ans[qans]=(x2-x1)*(y2-y1)*s;
				++Q;q[Q]=query(qans,Q,x1-1,y1-1,2,1);
				++Q;q[Q]=query(qans,Q,x2,y1-1,2,-1);
				++Q;q[Q]=query(qans,Q,x1-1,y2,2,-1);
				++Q;q[Q]=query(qans,Q,x2,y2,2,1);
				break;
		}
	}
	solve(1,Q);
	for(int i=1;i<=qans;i++)printf("%d\n",ans[i]);
	return 0;
}

