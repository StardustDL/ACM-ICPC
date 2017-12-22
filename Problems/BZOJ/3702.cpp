/*
二叉树
分析：交换子树不影响上层节点的答案，
		线段树维护逆序对，DFS过程中合并子线段树，统计答案。 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200000;
typedef long long LL;
int root[2*MAXN+3],l[2*MAXN+3],r[2*MAXN+3],v[2*MAXN+3],tot=0,n;
int sum[20*MAXN+3],lc[20*MAXN+3],rc[20*MAXN+3],cnt=0;
void input(int x){
	scanf("%d",&v[x]);
	if(v[x]!=0)return;
	l[x]=++tot;input(l[x]);
	r[x]=++tot;input(r[x]);
}
void update(int x){
	sum[x]=sum[lc[x]]+sum[rc[x]];
}
void build(int &x,int l,int r,int pos){
	if(!x)x=++cnt;
	if(l==r){sum[x]=1;return;}
	int mid=(l+r)>>1;
	if(pos<=mid)build(lc[x],l,mid,pos);
	else build(rc[x],mid+1,r,pos);
	update(x);
}
LL nx1,nx2;
int merge(int x,int y){
	if(!x || !y)return x+y;
	nx1+=(LL)sum[lc[x]]*sum[rc[y]];
	nx2+=(LL)sum[rc[x]]*sum[lc[y]];
	lc[x]=merge(lc[x],lc[y]);
	rc[x]=merge(rc[x],rc[y]);
	update(x);
	return x;
}
LL ans=0;
void solve(int x){
	if(x==0)return;
	solve(l[x]);solve(r[x]);
	if(v[x]==0){
		nx1=nx2=0;
		root[x]=merge(root[l[x]],root[r[x]]);
		ans+=min(nx1,nx2);
	}
}
int main(){
	scanf("%d",&n);input(tot=1);
	for(int i=1;i<=tot;i++)if(v[i])build(root[i],1,n,v[i]);
	solve(1);
	printf("%lld\n",ans);
	return 0;
}
