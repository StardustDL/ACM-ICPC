/*
巧克力王国
分析：KDTree暴力 
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=50000;
LL A,B,C,ans;
int D,n,m,root;
struct Point{
	int d[2],mx[2],mn[2],v,l,r;
	LL sum;
	int& operator [](int ind){
		return d[ind];
	}
	bool operator <(const Point &p)const{
		return d[D]<p.d[D];
	}
}temp[MAXN+3];
inline bool check(int x,int y){
	return A*x+B*y<C;
}
int calc(Point &p){
	return check(p.mn[0],p.mn[1])+check(p.mn[0],p.mx[1])+check(p.mx[0],p.mn[1])+check(p.mx[0],p.mx[1]);
}
void Min(int &x,int y){
	if(y<x)x=y;
}
void Max(int &x,int y){
	if(y>x)x=y;
}
struct kdTree{
	Point ps[MAXN+3];
	void update(int k){
		int l=ps[k].l,r=ps[k].r;
		for(int i=0;i<2;i++){
			ps[k].mn[i]=ps[k].mx[i]=ps[k][i];
			if(l){
				Min(ps[k].mn[i],ps[l].mn[i]);
				Max(ps[k].mx[i],ps[l].mx[i]);
			}
			if(r){
				Min(ps[k].mn[i],ps[r].mn[i]);
				Max(ps[k].mx[i],ps[r].mx[i]);
			}
		}
		ps[k].sum=ps[k].v+ps[l].sum+ps[r].sum;
	}
	int build(int l,int r,int curD){
		D=curD;int mid=(l+r)>>1;
		nth_element(temp+l,temp+mid,temp+r);
		ps[mid]=temp[mid];
		if(l<mid)ps[mid].l=build(l,mid-1,curD^1);
		if(r>mid)ps[mid].r=build(mid+1,r,curD^1);
		update(mid);
		return mid;
	}
	void query(int k){
		int l=ps[k].l,r=ps[k].r;
		if(check(ps[k][0],ps[k][1]))ans+=ps[k].v;
		if(l){
			int t=calc(ps[l]);
			if(t==4)ans+=ps[l].sum;
			else if(t)query(l);
		}
		if(r){
			int t=calc(ps[r]);
			if(t==4)ans+=ps[r].sum;
			else if(t)query(r);
		}
	}
}kd;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&temp[i][0],&temp[i][1],&temp[i].v);
	root=kd.build(1,n,0);
	while(m--){
		scanf("%lld%lld%lld",&A,&B,&C);ans=0;kd.query(root);//第一次交，忘输入用lld了，WA了 
		printf("%lld\n",ans);
	}
	return 0;
}

