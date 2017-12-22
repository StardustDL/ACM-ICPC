/*
借教室
分析：线段树实现，会超时，也可以优化，能AC 
*/
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f; 
#define LC(x) (x<<1)
#define RC(x) (x<<1|1)
struct Segment_Tree{
	struct node{int l,r,sum,tag;}dat[MAXN<<2+3];
	int n;
	void clear(int n){
		memset(dat,0,sizeof(dat));
		this->n=n;
	}
	void update(int x){
		dat[x].sum=min(dat[LC(x)].sum,dat[RC(x)].sum);
	}
	void pushdown(int x){
		node &t=dat[x];
		if(t.tag!=0){
			node &ll=dat[LC(x)],&rr=dat[RC(x)];
			ll.tag+=t.tag;
			ll.sum+=t.tag;
			rr.tag+=t.tag;
			rr.sum+=t.tag;
			t.tag=0;
		}
	}
	void build(int *arr,int l,int r,int x){
		dat[x].l=l;dat[x].r=r;
		if(l==r){dat[x].sum=arr[l];return;}
		int mid=(l+r)>>1;
		build(arr,l,mid,LC(x));
		build(arr,mid+1,r,RC(x));
		update(x);
	}
	int query(int l,int r,int x){
		node &X=dat[x];
		if(X.l>=l&&X.r<=r)return X.sum;
		int ans=INF,mid=(X.l+X.r)>>1;
		pushdown(x);
		if(l<=mid)ans=min(ans,query(l,r,LC(x)));
		if(r>mid)ans=min(ans,query(l,r,RC(x)));
		return ans;
	}
	void add(int l,int r,int ad,int x){
		node &X=dat[x];
		if(X.l>=l&&X.r<=r){X.tag+=ad;X.sum+=ad;return;}
		int mid=(X.l+X.r)>>1;
		pushdown(x);
		if(l<=mid)add(l,r,ad,LC(x));
		if(r>mid)add(l,r,ad,RC(x));
		update(x);
	}
};
Segment_Tree T;
int n,m,r[MAXN+3],d[MAXN+3],s[MAXN+3],t[MAXN+3];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
	}
	T.build(r,1,n,1);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&d[i],&s[i],&t[i]);
		T.add(s[i],t[i],-d[i],0);
		if(T.query(1,n,0)<0){
			printf("-1\n%d",i);return 0;
		}
	}
	printf("0");
	return 0;
}
