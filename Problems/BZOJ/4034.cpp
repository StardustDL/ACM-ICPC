/*
[HAOI2015]T2
·ÖÎö£ºÊ÷Á´ÆÊ·Ö 
*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=100000;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,cnt;
int last[MAXN+3];
int id,pos[MAXN+3],mx[MAXN+3],v[MAXN+3];
int top[MAXN+3],size[MAXN+3],fa[MAXN+3];
LL tag[4*MAXN+3],sum[4*MAXN+3];
struct edge{
	int v,nxt;
}e[2*MAXN+3];
void insert(int u,int v){
	e[++cnt]=(edge){v,last[u]};last[u]=cnt;
	e[++cnt]=(edge){u,last[v]};last[v]=cnt;
}
void dfs(int x){
	size[x]=1;
	for(int i=last[x];i;i=e[i].nxt)
		if(e[i].v!=fa[x]){
			fa[e[i].v]=x;
			dfs(e[i].v);
			size[x]+=size[e[i].v];
		}
}
void dfs2(int x,int tp){
	top[x]=tp;pos[x]=mx[x]=++id;
	int son=0;
	for(int i=last[x];i;i=e[i].nxt)
		if(e[i].v!=fa[x]&&size[e[i].v]>size[son])son=e[i].v;
	if(son)dfs2(son,tp),mx[x]=max(mx[x],mx[son]);
	for(int i=last[x];i;i=e[i].nxt){
		if(e[i].v==fa[x]||e[i].v==son)continue;
		dfs2(e[i].v,e[i].v);
		mx[x]=max(mx[x],mx[e[i].v]);
	}
}
void pushdown(int x,int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	tag[x<<1]+=tag[x];tag[x<<1|1]+=tag[x];
	sum[x<<1]+=tag[x]*(mid-l+1);
	sum[x<<1|1]+=tag[x]*(r-mid);
	tag[x]=0;
}
void add(int x,int l,int r,int L,int R,LL val){
	if(tag[x])pushdown(x,l,r);
	if(L<=l&&r<=R){tag[x]+=val;sum[x]+=(r-l+1)*val;return;}
	int mid=(l+r)>>1;
	if(L<=mid)add(x<<1,l,mid,L,R,val);
	if(R>mid)add(x<<1|1,mid+1,r,L,R,val);
	sum[x]=sum[x<<1]+sum[x<<1|1];
}
LL query(int x,int l,int r,int L,int R){
	if(tag[x])pushdown(x,l,r);
	if(L<=l&&r<=R)return sum[x];
	int mid=(l+r)>>1;LL ans=0;
	if(L<=mid)ans+=query(x<<1,l,mid,L,R);
	if(R>mid)ans+=query(x<<1|1,mid+1,r,L,R);
	return ans;
}
LL query(int x){
	LL ans=0;
	while(top[x]!=1){
		ans+=query(1,1,n,pos[top[x]],pos[x]);
		x=fa[top[x]];
	}
	ans+=query(1,1,n,pos[1],pos[x]);
	return ans;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)v[i]=read();
	for(int i=1;i<n;i++)
		insert(read(),read());
	dfs(1);dfs2(1,1);
	for(int i=1;i<=n;i++)
		add(1,1,n,pos[i],pos[i],v[i]);
	int opt,x,a;
	while(m--){
		opt=read();x=read();
		switch(opt){
			case 1:
				add(1,1,n,pos[x],pos[x],read());
				break;
			case 2:
				add(1,1,n,pos[x],mx[x],read());
				break;
			case 3:
				printf("%lld\n",query(x));
				break; 
		}
	}
	return 0;
}
