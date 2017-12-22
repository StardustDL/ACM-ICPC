/*
线段树练习 2
分析：ZKW线段树实现，区间修改单点查询，每次打标记，查询时累加标记，注意不下传 
*/
#include<iostream>
using namespace std;
const int MAXN=100000;
struct zkw{
	int dat[4*MAXN+3],M,tag[MAXN+3];
	void pushup(int x){dat[x]=dat[x<<1]+dat[x<<1|1];}
	void build(int *a,int n){
		for(M=1;M<=n+1;M<<=1);
		for(int i=1;i<=n;i++)dat[M+i]=a[i];
		for(int i=M-1;i>0;i--)pushup(i);
	}
	void change(int x,int v){
		for(dat[x+=M]=v,x>>=1;x;x>>=1)pushup(x);
	}
	void add(int l,int r,int ad){
		for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
			if(~l&1)tag[l^1]+=ad;
			if(r&1)tag[r^1]+=ad;
		}
	}
	int query(int x){
		int ans=0;
		for(ans+=dat[x+=M];x;x>>=1)ans+=tag[x];
		return ans;
	}
}T;
int n,a[MAXN+3];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	T.build(a,n);
	int q,x,y,z,t;
	cin>>q;
	while(q-->0){
		cin>>x>>y;
		if(x==1){
			cin>>z>>t;
			T.add(y,z,t);
		}
		else cout<<T.query(y)<<endl;
	}
	return 0;
}
