/*
Trick or Treat
���⣺��ƽ������ϵ�ϸ���һЩ�㣬Ȼ������X������һ��ʹ�����е㵽�õ�ľ�������ֵ��С��
���������x0��������㣬��ô�õ��������Ҷ���ʹ������������������ 
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
		printf("%.9lf %.9lf\n",l,calc(l));//�˴���Ҫ����min(v1,v2),���¼��� 
	}
	return 0 ;
}
