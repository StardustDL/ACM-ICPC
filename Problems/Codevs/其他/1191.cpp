/*
数轴染色
分析：区间查询，区间修改 
*/
#include<iostream>
using namespace std;
const int MAXN=200000;
typedef long long LL;
struct node{
	int l,r,lazy;
	LL val;
	node(){
		l=r=val=lazy=0;
	}
};
struct segment_tree{
	node ns[MAXN*3+3];
	
	void updata(int x){
		ns[x].val=(ns[x<<1].lazy!=0?0:ns[x<<1].val)
				 +(ns[(x<<1)+1].lazy!=0?0:ns[(x<<1)+1].val);
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
	
	void set(int l,int r,int val,int x){
		node &t=ns[x];
		if(l<=t.l&&r>=t.r){
			t.lazy+=val; 
			return;
		}
		int mid=(t.l+t.r)>>1;
		if(l<=mid){
			set(l,r,val,x<<1);
		}
		if(r>mid){
			set(l,r,val,(x<<1)+1);
		}
		updata(x);
	}
	
	LL query(int l,int r,int x){
		node &t=ns[x];
		LL ans=0;
		int mid=(t.l+t.r)>>1;
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
int n,a[MAXN+3],m,x,y;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)a[i]=1;
	root.build(a,1,n,1);
	while(m-->0){
		cin>>x>>y;
		root.set(x,y,1,1);
		cout<<root.query(1,n,1)<<endl;
	}
	return 0;
}
