/*
绳子围点
分析：先求凸包，再求面积，再用欧几里德算法求边界上的点数，
	  怎么求点数：给定两个格点，问这两个格点连成的线段上有多少个格点，感觉是gcd(x1-x0,y1-y0)+1
	  然后Pick定理求内部点数：
	  S=I+（A/2）-1;
		s是面积，I是多边形内部整点，A是边上整点;
		A 用GCD求。	 
		注意细节，longlong，abs自己写 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=200000,INF=0x3f3f3f3f;
typedef long long LL; 
struct Point{
	LL x,y;
}ps[MAXN+3];
LL Cross(Point &a,Point &b,Point &base){
	return (LL)(a.x-base.x)*(b.y-base.y)-(LL)(a.y-base.y)*(b.x-base.x);
}
bool cmp(const Point &a,const Point &b){
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
LL absll(LL a){
	return a>0?a:-a;
}
int n,m;
Point bag[2*MAXN+3];
void andrewScan(){
	sort(ps+1,ps+n+1,cmp); 
	m=2;bag[1]=ps[1];bag[2]=ps[2];
	for(int i=3;i<=n;i++){
		while(m>1&&Cross(bag[m],ps[i],bag[m-1])<0)m--;
		bag[++m]=ps[i];
	}
	for(int i=n-1;i>=1;i--){
		while(m>1&&Cross(bag[m],ps[i],bag[m-1])<0)m--;
		bag[++m]=ps[i];
	}
	m--;//这里要-1,因为会重复加入第一个点 
}
LL TwiceArea(){
	LL ans=0;
	for(int i=3;i<=m;i++){
		ans+=Cross(bag[i-1],bag[i],bag[1]);
	}
	return ans;
}
LL gcd(LL a,LL b){
	//cout<<b<<endl;
	return b?gcd(b,a%b):a;
}
LL LinePoint(int i){
	//cout<<m<<"!!"<<endl;
	int j=i==m?1:i+1;
	return gcd(absll(bag[i].x-bag[j].x),absll(bag[i].y-bag[j].y));
}
LL Pick(){
	LL ar=TwiceArea(),ln=0;
	//cout<<ar<<endl;
	for(int i=1;i<=m;i++){
		ln+=LinePoint(i);
	}
	return (ar-ln+2)/2+ln;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&ps[i].x,&ps[i].y);
	andrewScan();
	cout<<Pick()<<endl;
	return 0;
}

