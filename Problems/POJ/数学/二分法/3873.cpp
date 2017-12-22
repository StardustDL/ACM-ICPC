/*
Trick or Treat
题意：在平面坐标系上给定一些点，然后让在X轴上找一点使得所有点到该点的距离的最大值最小。
分析：如果x0点是所求点，那么该点向左向右都会使得最大距离变大，于是三分 
*/
#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
const double eps = 1e-10;
double x[MAXN+3],y[MAXN+3];
int n;
double _distance(int i,double xx){
	return sqrt(y[i]*y[i]+(x[i]-xx)*(x[i]-xx));
}
double calc(double p){
	double res=0.0;
	for(int i=0;i<n;i++)
		res=max(res,_distance(i,p));
	return res;
}
int main(){
	while(scanf("%d",&n),n){
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		double l=*min_element(x,x+n),r=*max_element(x,x+n),p1=0,p2=0,v1=0,v2=0;
		while(r-l>eps){
			p1=l+(r-l)/3.0;
			p2=r-(r-l)/3.0;
			v1=calc(p1),v2=calc(p2);
			if(v1>v2)l=p1;
			else r=p2;
		}
		printf("%.9lf %.9lf\n",l,calc(l));//此处不要调用min(v1,v2),重新计算 
	}
	return 0 ;
}
