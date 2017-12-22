/*
[Usaco2008 Nov]lites 开关灯
分析：线段树，lazy用异或即可 
*/
#include<cstdio>
using namespace std;
const int MAXN=100000;
typedef long long LL;
struct node{
	int l,r,lazy;
	LL val;
	node(){
		l=r=val=0;
		lazy=0;
	}
};
struct segment_tree{
	node ns[MAXN*3+3];
	
	void updata(int x){
		ns[x].val=ns[x<<1].val+ns[(x<<1)+1].val;
	}
	void pushdown(int x){
		node &t=ns[x];
		if(t.lazy!=0){
			node &ll=ns[x<<1],&rr=ns[(x<<1)+1];
			ll.lazy^=t.lazy;
			ll.val=ll.r-ll.l+1-ll.val;
			rr.lazy^=t.lazy;
			rr.val=rr.r-rr.l+1-rr.val;
			t.lazy=0;
		}
	}
	void build(int l,int r,int x){
		ns[x].l=l;ns[x].r=r;
		if(l==r){ns[x].val=0;return;}
		int mid=(l+r)>>1;
		build(l,mid,x<<1);
		build(mid+1,r,(x<<1)+1);
		updata(x);
	}
	void set(int l,int r,int x){
		node &t=ns[x];
		if(l<=t.l&&r>=t.r){
			t.lazy^=1;
			t.val=t.r-t.l+1-t.val;//先计算好 
			return;
		}
		int mid=(t.l+t.r)>>1;
		pushdown(x);
		if(l<=mid)set(l,r,x<<1);
		if(r>mid)set(l,r,(x<<1)+1);
		updata(x);
	}
	
	LL query(int l,int r,int x){
		node &t=ns[x];
		LL ans=0;
		int mid=(t.l+t.r)>>1;
		if(l<=t.l&&r>=t.r)return t.val;
		pushdown(x);//push不要放在前面 
		if(l<=mid)ans+=query(l,r,x<<1);
		if(r>mid)ans+=query(l,r,(x<<1)+1);
		return ans;
	}
}root;
int n,m,x,y,z;
int main(){
	scanf("%d%d",&n,&m);
	root.build(1,n,1);
	while(m--){
		scanf("%d",&x);
		switch(x){
			case 0:
				scanf("%d%d",&y,&z);
				root.set(y,z,1);
				break;
			case 1:
				scanf("%d%d",&y,&z);
				printf("%d\n",root.query(y,z,1));
				break;
		}
	}
	return 0;
}
