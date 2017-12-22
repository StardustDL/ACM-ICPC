/*
线段树练习
分析：ZKW线段树实现，区间查询，单点修改 
*/
#include<iostream>
using namespace std;
const int MAXN=100000;
struct zkw{
	int dat[4*MAXN+3],M;
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
	int getval(int x){
		return dat[x+M];
	}
	int query(int l,int r){
		int ans=0;
		for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
			if(~l&1)ans+=dat[l^1];
			if(r&1)ans+=dat[r^1];
		}
		return ans;
	}
}T;
int n,a[MAXN+3];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int q,x,y,z;
	cin>>q;
	while(q-->0){
		cin>>x>>y>>z;
		if(x==1)T.change(y,T.getval(y)+z);
		else cout<<T.query(y,z)<<endl; 
	}
	return 0;
}
