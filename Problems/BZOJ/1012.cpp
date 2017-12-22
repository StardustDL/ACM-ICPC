/*
[JSOI2008]最大数maxnumber
分析：倒过来存，就可以避免插入操作，直接线段树，但是不能用cin,cout,会RE，另一种做法：单调队列+二分 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#define LC(x) (x<<1)
#define RC(x) (x<<1|1)
using namespace std;
typedef int LL; 
const int INF=0x3f3f3f3f,MAXN=200000+5;
LL mx[MAXN*4];
void update(int x){
	mx[x]=max(mx[LC(x)],mx[RC(x)]);
}
void add(int p,LL ad,int l,int r,int x){
	if(l==r){mx[x]+=ad;return;}
	int mid=(l+r)>>1;
	if(p>mid)add(p,ad,mid+1,r,RC(x));
	else add(p,ad,l,mid,LC(x));
	update(x);
}
LL query(int l,int r,int x,int xl,int xr){
	if(l<=xl&&r>=xr)return mx[x];
	int mid=(xl+xr)>>1;
	LL ans=0;
	if(l<=mid)ans=max(ans,query(l,r,LC(x),xl,mid));
	if(r>mid)ans=max(ans,query(l,r,RC(x),mid+1,xr));
	return ans;
}
int m,x,tot=0;
LL t=0,d;
char c;
int main(){
	scanf("%d%d",&m,&d);
	for(int i=1;i<=m;i++){
		scanf("\n%c %d",&c,&x);
		//cout<<c<<endl; 
		if(c=='A'){
			add(++tot,((LL)x+t)%d,1,m,1);
			//cout<<tot<<endl;
		}
		else printf("%d\n",t=query(tot-x+1,tot,1,1,m));
	}
	return 0;
}
