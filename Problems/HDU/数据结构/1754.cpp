/*
I Hate It
·ÖÎö£ºÏß¶ÎÊ÷ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#define LC(x) (x<<1)
#define RC(x) (x<<1|1)
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200000;
struct node{int l,r,mx;node(){l=r=mx=0;}};
node dat[(MAXN+3)*4]; 
void update(int x){dat[x].mx=max(dat[LC(x)].mx,dat[RC(x)].mx);} 
void build(int *a,int l,int r,int x){
	node &T=dat[x];
	T.l=l;T.r=r;
	if(l==r){T.mx=a[l];return;}	
	int mid=(l+r)>>1;
	build(a,l,mid,LC(x));
	build(a,mid+1,r,RC(x));
	update(x);
}
int query(int l,int r,int x){
	node &T=dat[x];
	if(l<=T.l&&r>=T.r)return T.mx;
	int ans=0,mid=(T.l+T.r)>>1;
	if(l<=mid)ans=max(ans,query(l,r,LC(x)));
	if(r>mid)ans=max(ans,query(l,r,RC(x)));
	return ans;
}
void change(int p,int val,int x){
	if(dat[x].l==dat[x].r){dat[x].mx=val;return;}
	int mid=(dat[x].l+dat[x].r)>>1;
	if(p<=mid)change(p,val,LC(x));
	else change(p,val,RC(x));
	update(x);
}
int A[MAXN+3],n,m,a,b;
int main(){
	char c[13];
	while(scanf("%d%d",&n,&m)!=EOF){ 
		for(int i=1;i<=n;i++)scanf("%d",&A[i]);
		build(A,1,n,1);
		while(m--){
			scanf("\n%s %d %d",c,&a,&b);
			if(c[0]=='Q')printf("%d\n",query(a,b,1));
			else change(a,b,1);
		}
	} 
	return 0;
}

