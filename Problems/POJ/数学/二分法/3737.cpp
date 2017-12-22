/*
UmBasketella
���⣺��һ�����Ϊs��Բ׶������������Լ���Ӧ�ĵ���뾶�͸ߡ�
��������������ѧ�Ƶ���û�п�����
	  	S=pi*r*l + pi*r*r
		l=sqrt(r*r+h*h)�� �����ã� r*2= s*s/(pi*pi*h*h+2*pi*s)
		V=(1/3)*pi*r*r*h������r*2���󵼣���һ�׵���Ϊ0���ó����
		
		h=sqrt(2*s/pi)
		r=sqrt(s*s/(pi*pi*h*h+2*pi*s))
		v=(1.0/3.0)*(s*s)*h/(pi*h*h+2*s) 
	  ����һ�����ֵķ��������Ǻʹ��в�ࣺ
	  	V=1/3*r*r*h,��r*r=hʱr*r*hȡ�����ֵ����ʱ����S=pi*r(r+sqrt(r*r+r^4))
	  	���ֳ�r������𰸣������в��
	  ����������
	  	�����ڵ���͹�Ժ���������κ���
		  	double cal(){}//������Ŀ����Ҫ��ֵ
			while(l+eps<r){
			    m1=l+(r-l)/3;
			    m2=r-(r-l)/3;
			    v1=cal(m1);
			    v2=cal(m2);
			    if(v1<v2)l=m1;
			    else r=m2;
			} 
			��ʱr(��l)�����ֵ��ȡֵ�� 
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

