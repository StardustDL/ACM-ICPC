/*
线段树练习
分析：区间查询，单点修改，可以线段树或树状数组 
*/
#include<iostream>
using namespace std;
const int MAXN=100000;
struct node{
	int l,r,val,lazy;
	node(){
		l=r=val=lazy=0;
	}
};
struct segment_tree{
	node ns[MAXN*3+3];
	int n;
	
	void updata(int x){
		ns[x].val=ns[x<<1].val+ns[(x<<1)+1].val;
	}
	void pushdown(int x){//注意push要处理好子节点的val，否则updata时会出错 
		node &t=ns[x];
		if(t.lazy!=0){
			node &ll=ns[x<<1],&rr=ns[(x<<1)+1];
			ll.lazy+=t.lazy;
			ll.val+=t.lazy*(ll.r-ll.l+1);
			rr.lazy+=t.lazy;
			rr.val+=t.lazy*(rr.r-rr.l+1);
			t.lazy=0;
		}
	}
	
	void build(int* arr,int l,int r,int x){
		ns[x].l=l;
		ns[x].r=r;
		if(l==r){
			ns[x].val=arr[l];
			return;
		}
		int mid=(l+r)>>1;
		build(arr,l,mid,x<<1);
		build(arr,mid+1,r,(x<<1)+1);
		updata(x);
	}
	
	void add(int l,int r,int ad,int x){
		node &t=ns[x];
		if(l<=t.l&&r>=t.r){
			t.lazy+=ad;
			t.val+=ad*(t.r-t.l+1);//先计算好 
			return;
		}
		int mid=(t.l+t.r)>>1;
		pushdown(x);
		if(l<=mid){
			add(l,r,ad,x<<1);
		}
		if(r>mid){
			add(l,r,ad,(x<<1)+1);
		}
		updata(x);
	}
	
	int query(int l,int r,int x){
		pushdown(x);
		node &t=ns[x];
		int ans=0,mid=(t.l+t.r)>>1;
		if(l<=t.l&&r>=t.r){
			return t.val;
		}
		if(l<=mid){
			ans+=query(l,r,x<<1);
		}
		if(r>mid){
			ans+=query(l,r,(x<<1)+1);
		}
		return ans;
	}
}root;
int n,a[MAXN+3],m,x,y,z;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	root.build(a,1,n,1);
	cin>>m;
	while(m-->0){
		cin>>x;
		switch(x){
			case 1:
				cin>>y>>z;
				root.add(y,y,z,1);
				break;
			case 2:
				cin>>y>>z;
				cout<<root.query(y,z,1)<<endl;
				break;
		}
	}
	return 0;
}
