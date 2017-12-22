/*
UmBasketella
题意：求一个面积为s的圆锥体的最大体积，以及对应的底面半径和高。
分析：网上有数学推导，没有看懂：
	  	S=pi*r*l + pi*r*r
		l=sqrt(r*r+h*h)， 联立得， r*2= s*s/(pi*pi*h*h+2*pi*s)
		V=(1/3)*pi*r*r*h，代入r*2，求导，令一阶导数为0，得出结果
		
		h=sqrt(2*s/pi)
		r=sqrt(s*s/(pi*pi*h*h+2*pi*s))
		v=(1.0/3.0)*(s*s)*h/(pi*h*h+2*s) 
	  想了一个二分的方法，但是和答案有差距：
	  	V=1/3*r*r*h,在r*r=h时r*r*h取得最大值，此时满足S=pi*r(r+sqrt(r*r+r^4))
	  	二分出r，求出答案，但是有差距
	  三分做法：
	  	适用于单峰凸性函数，如二次函数
		  	double cal(){}//计算题目所需要的值
			while(l+eps<r){
			    m1=l+(r-l)/3;
			    m2=r-(r-l)/3;
			    v1=cal(m1);
			    v2=cal(m2);
			    if(v1<v2)l=m1;
			    else r=m2;
			} 
			此时r(或l)是最大值的取值点 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#define sqr(x) ((x)*(x))
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
double s,pi;
bool check(double r){
	return 1+r*r<sqr(s/pi/r/r-1);
}
double ef(double l,double r,double eps){
	double mid;
	while(r-l>eps){
		mid=(l+r)/2.0;
		if(check(mid))l=mid;
		else r=mid;
	}
	return l;
}
double calc(double r){
	double l=s/pi/r-r,h=sqrt(l*l-r*r);
	return h*pi*sqr(r)/3;
}
double sf(double l,double r,double eps){
	double v1,v2,p1,p2;
	while(r-l>eps){
		p1=l+(r-l)/3;
		p2=r-(r-l)/3;
		v1=calc(p1),v2=calc(p2);
		if(v1<v2)l=p1;
		else r=p2;
	}
	return r;
}
int main(){
	pi=acos(-1.0);
	while(~scanf("%lf",&s)){
		double r=sf(0,sqrt(s/pi),1e-8);
		double l=s/pi/r-r;
		double h=sqrt(l*l-r*r);
		double v=pi*r*r*h/3.0;
		printf("%.2lf\n%.2lf\n%.2lf\n",v,h,r);
	}
	return 0;
}

