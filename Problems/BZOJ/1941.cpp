/*
[Sdoi2010]Hide and Seek
分析：k-d树，求最近点，最远点。 
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;
const int MAXN=500000,INF=0x3f3f3f3f;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,root,D;
struct P{
	int d[2],mn[2],mx[2],l,r;
	int& operator[](int x){return d[x];}
	P(int x=0,int y=0)
		{l=0,r=0;d[0]=x,d[1]=y;}  
}p[MAXN+3];
bool operator<(const P &a,const P &b){//按指定维排序 
	return a.d[D]<b.d[D];
}
inline int dis(P &a,P &b){
	return abs(a[0]-b[0])+abs(a[1]-b[1]);
}
struct kdtree{
	int ans;
	P t[2*MAXN+3],T;
	void update(int k){
		P &l=t[t[k].l],&r=t[t[k].r];
		for(int i=0;i<2;i++){
			if(t[k].l)t[k].mn[i]=min(t[k].mn[i],l.mn[i]),t[k].mx[i]=max(t[k].mx[i],l.mx[i]);
			if(t[k].r)t[k].mn[i]=min(t[k].mn[i],r.mn[i]),t[k].mx[i]=max(t[k].mx[i],r.mx[i]);
		}
	}
	int build(int l,int r,int now){
		D=now;
		int mid=(l+r)>>1;
		nth_element(p+l,p+mid,p+r+1);
		t[mid]=p[mid];
		for(int i=0;i<2;i++)
			t[mid].mn[i]=t[mid].mx[i]=t[mid][i];
		if(l<mid)t[mid].l=build(l,mid-1,now^1);
		if(r>mid)t[mid].r=build(mid+1,r,now^1);
		update(mid);
		return mid;
	}
	int getmn(int k,P p){//取最近 
		int tmp=0;//如果p[i]属于[mn[i]..mx[i]] 则会得到0，否则会选较近的mn[i]或mx[i] eg.mn[i]<mx[i]<p[i] 选mx[i] p[i]<mn[i]<mx[i] 选mn[i] 
		for(int i=0;i<2;i++)
			tmp+=max(0,t[k].mn[i]-p[i]);
		for(int i=0;i<2;i++)
			tmp+=max(0,p[i]-t[k].mx[i]);
		return tmp;
	}
	int getmx(int k,P p){//取最远 
		int tmp=0;
		for(int i=0;i<2;i++)
			tmp+=max(abs(t[k].mn[i]-p[i]),abs(p[i]-t[k].mx[i]));//计算方法略有不同（因为是最远，所以随便abs了） 
		return tmp;
	}
	void query_mn(int k,int now){
		int d=dis(t[k],T),dl=INF,dr=INF;
		if(d)ans=min(ans,d);//注意这里= =，要把自己排除（即距离=0） 
		if(t[k].l)dl=getmn(t[k].l,T);
		if(t[k].r)dr=getmn(t[k].r,T);
		if(dl<dr){
			if(dl<ans)query_mn(t[k].l,now^1);
			if(dr<ans)query_mn(t[k].r,now^1);
		}
		else{ 
			if(dr<ans)query_mn(t[k].r,now^1);
			if(dl<ans)query_mn(t[k].l,now^1);
		}
	}
	void query_mx(int k,int now){
		int d=dis(t[k],T),dl=-INF,dr=-INF;
		ans=max(ans,d);
		if(t[k].l)dl=getmx(t[k].l,T);
		if(t[k].r)dr=getmx(t[k].r,T);
		if(dl>dr){
			if(dl>ans)query_mx(t[k].l,now^1);
			if(dr>ans)query_mx(t[k].r,now^1);
		}
		else{ 
			if(dr>ans)query_mx(t[k].r,now^1);
			if(dl>ans)query_mx(t[k].l,now^1);
		}
	}
	int query(P p){
		T=p;int res=0;
		ans=-INF;query_mx(root,0);
		res+=ans;
		ans=INF;query_mn(root,0);
		res-=ans;
		return res;
	}
}kd;
int x[MAXN+3],y[MAXN+3];
int main(){
	n=read();
	for(int i=1;i<=n;i++)p[i][0]=x[i]=read(),p[i][1]=y[i]=read();
	root=kd.build(1,n,0);
	int ans=INF;
	for(int i=1;i<=n;i++){
		ans=min(ans,kd.query(P(x[i],y[i])));
	}
	printf("%d\n",ans);
	return 0;
}
