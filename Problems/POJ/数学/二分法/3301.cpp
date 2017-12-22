/*
Texas Trip
题意：平面上给你很多的点，要你用一最小面积的个正方形把所有的点都覆盖完。注意正方形不一定平行于坐标系
分析：因为正方形从0度到180度变化的过程中，把所有点覆盖，面积肯定是有一个最小峰值，是一个凸函数。因此可以用三分法解决。这里有一个难点就是已知两个定点的x,y坐标，过这两个点做两条平行线，平行线并与x轴成d度的角，怎么算出两条平行线的距离。
	  d1 = fabs(cos(d)*(yi-yj)-sin(d)*(xi-xj));
	  d2 = fabs*(sin(d)*(yi-yj)+cos(d)*(xi-xj));
	  为什么会有两个距离呢？
	  因为两个点可以做出两对平行线，一条是与x轴成d度角，另一个是与x成（180-d）度角 
*/
#include<iostream>
#include<cmath>
using namespace std;
const double eps=1e-9;
int T,n,x[1000],y[1000];
double pi=acos(-1.0);
double calc(double d){
	double dis=0.0,s=sin(d),c=cos(d);
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
			dis=max(dis,max(fabs(c*(y[i]-y[j])-s*(x[i]-x[j])),fabs(s*(y[i]-y[j])-c*(x[i]-x[j]))));
 	return (dis*dis);
}
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
		double l=0,r=2*pi,v1,v2,p1,p2;
		while(r-l>eps){
			p1=l+(r-l)/3.0;
			p2=r-(r-l)/3.0;
			v1=calc(p1),v2=calc(p2);
			if(v1<v2)r=p2;
			else l=p1;
		}
		printf("%.2lf\n",min(v1,v2));
	}
	return 0;
}
