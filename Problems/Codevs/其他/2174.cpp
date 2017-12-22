/*
忠诚S
分析：区间查询最小值，单点修改
*/
#include<iostream>
#include<cmath> 
#include<algorithm>
using namespace std;
const int MAXN=100000,INF=1<<30;
struct node{
	int l,r,val;
	node(){
		l=r=val=0;
	}
};
struct segment_tree{
	node ns[MAXN*3+3];
	
	void updata(int x){
		ns[x].val=min(ns[x<<1].val,ns[(x<<1)+1].val);
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
	
	void set(int e,int ad,int x){
		node &t=ns[x];
		if(t.l==t.r&&t.l==e){
			t.val=ad;
			return;
		}
		int mid=(t.l+t.r)>>1;
		if(e<=mid){
			set(e,ad,x<<1);
		}
		else{
			set(e,ad,(x<<1)+1);
		}
		updata(x);
	}
	
	int query(int l,int r,int x){
		node &t=ns[x];
		int ans=INF,mid=(t.l+t.r)>>1;
		if(l<=t.l&&r>=t.r){
			return t.val;
		}
		if(l<=mid){
			ans=min(ans,query(l,r,x<<1));
		}
		if(r>mid){
			ans=min(ans,query(l,r,(x<<1)+1));
		}
		return ans;
	}
}root;
int n,a[MAXN+3],m,x,y,z;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	root.build(a,1,n,1);
	while(m-->0){
		cin>>x;
		switch(x){
			case 1:
				cin>>y>>z;
				cout<<root.query(y,z,1)<<" ";
				break;
			case 2:
				cin>>y>>z;
				root.set(y,z,1);
				break;
		}
	}
	return 0;
}
