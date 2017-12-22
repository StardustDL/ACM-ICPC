/*
简单题
分析：强制在线就用kdtree来维护T T
		常数太丑会T，那就每插入若干次重构整棵树 
*/ 
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=200000;
int n,curD;
LL read(){
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct Point{
	int mn[2],mx[2],p[2],l,r,val;
	LL sum;
	int& operator [](int ind){return p[ind];}
	bool operator ==(const Point &x)const{
		return p[0]==x.p[0]&&p[1]==x.p[1];
	}
	bool operator <(const Point &x)const{
		return p[curD]<x.p[curD];
	}
}tmp[MAXN+3];
bool in(int x1,int y1,int x2,int y2,int X1,int Y1,int X2,int Y2)
{
	return x1<=X1&&X2<=x2&&y1<=Y1&&Y2<=y2;
}
bool out(int x1,int y1,int x2,int y2,int X1,int Y1,int X2,int Y2)
{
	return x1>X2||x2<X1||y1>Y2||y2<Y1;
}
struct kdtree{
	Point ps[MAXN+3],ins;
	int cnt,rt;
	void update(int k){
		int l=ps[k].l,r=ps[k].r;
		for(int i=0;i<2;i++){
			ps[k].mn[i]=ps[k].mx[i]=ps[k][i];
			if(l){
				ps[k].mn[i]=min(ps[k].mn[i],ps[l].mn[i]);
				ps[k].mx[i]=max(ps[k].mx[i],ps[l].mx[i]);
			}
			if(r){
				ps[k].mn[i]=min(ps[k].mn[i],ps[r].mn[i]);
				ps[k].mx[i]=max(ps[k].mx[i],ps[r].mx[i]);
			}
		}
		ps[k].sum=ps[k].val+ps[l].sum+ps[r].sum;
	}
	void insert(int &k,bool D){
		if(k==0){
			k=++cnt;
			ps[k].mn[0]=ps[k].mx[0]=ps[k][0]=ins[0];
			ps[k].mn[1]=ps[k].mx[1]=ps[k][1]=ins[1];
		} 
		if(ps[k]==ins){
			ps[k].val+=ins.val;ps[k].sum+=ins.val;return;
		}
		if(ins[D]<ps[k][D])insert(ps[k].l,D^1);
		else insert(ps[k].r,D^1);
		update(k);
	}
	int rebuild(int l,int r,bool D){
		if(l>r)return 0;
		int mid=(l+r)>>1;
		curD=D;nth_element(tmp+l,tmp+mid,tmp+r+1);
		ps[mid]=tmp[mid];
		ps[mid].l=rebuild(l,mid-1,D^1);
		ps[mid].r=rebuild(mid+1,r,D^1);
		update(mid);
		return mid;
	}
	LL query(int k,int x1,int y1,int x2,int y2){
		if(k==0)return 0;
		if(in(x1,y1,x2,y2,ps[k].mn[0],ps[k].mn[1],ps[k].mx[0],ps[k].mx[1]))return ps[k].sum;
		if(out(x1,y1,x2,y2,ps[k].mn[0],ps[k].mn[1],ps[k].mx[0],ps[k].mx[1]))return 0;
		LL tmp=0;
		if(in(x1,y1,x2,y2,ps[k][0],ps[k][1],ps[k][0],ps[k][1]))tmp+=ps[k].val;
		tmp+=query(ps[k].l,x1,y1,x2,y2)+query(ps[k].r,x1,y1,x2,y2);
		return tmp;
	}
}T;
LL lastans=0;
int main()
{
	n=read();
	int opt,x,y,x2,y2,A,m=10000;
	while(1){
		opt=read();if(opt==3)break;
		x=read()^lastans;y=read()^lastans;
		if(opt==1){
			A=read()^lastans;T.ins[0]=x;T.ins[1]=y;
			T.ins.val=T.ins.sum=A;
			T.insert(T.rt,0);
			if(T.cnt==m){
				for(int i=1;i<=T.cnt;i++)tmp[i]=T.ps[i];
				T.rt=T.rebuild(1,T.cnt,0);m+=10000;
			}
		}
		if(opt==2){
			x2=read()^lastans;y2=read()^lastans;
			lastans=T.query(T.rt,x,y,x2,y2);
			printf("%lld\n",lastans);
		}
	}
	return 0;
}

