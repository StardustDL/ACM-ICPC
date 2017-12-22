/*
线段树练习 3
分析：ZKW线段树实现 
*/
#include<iostream>
using namespace std;
const int MAXN=200000;
typedef long long LL;
struct zkw{
	LL dat[4*MAXN+3],M;
	void pushup(int x){
		dat[x]=dat[x<<1]+dat[x<<1|1];
	}
	void build(int *a,int n){
		for(M=1;M<=n+1;M<<=1);
		for(int i=1;i<=n;i++)dat[M+i]=a[i];
		for(int i=M-1;i>0;i--)pushup(i);
	}
	void change(int x,int v){
		for(dat[x+=M]=v,x>>=1;x;x>>=1)pushup(x);
	}
	void add(int l,int r,LL ad){
		for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
			if(~l&1)dat[l^1]+=ad;
			if(r&1)dat[r^1]+=ad;
			ad>>=1;
		}
	}
	LL query(int l,int r){
		LL ans=0;
		for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
			if(~l&1)ans+=dat[l^1];
			if(r&1)ans+=dat[r^1];
		}
		return ans;
	}
}T;
int n,a[MAXN+3];
int main(){
	cin>>n;a[1]=0;
	for(int i=2;i<=n+1;i++)cin>>a[i];
	T.build(a,n+1);
	//for(int i=1;i<1<<T.deep+1;i++)cout<<T.dat[i]<<endl;
	int q,x,y,z,k;cin>>q;
	while(q-->0){
		cin>>x;
		if(x==1){
			cin>>y>>z>>k;
			T.add(y+1,z+1,(LL)k);
		}
		else {
			cin>>y>>z;
			cout<<T.query(y+1,z+1)<<endl;
		}
	}
	return 0;
}
