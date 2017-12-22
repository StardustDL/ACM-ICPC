/*
Texas Trip
���⣺ƽ���ϸ���ܶ�ĵ㣬Ҫ����һ��С����ĸ������ΰ����еĵ㶼�����ꡣע�������β�һ��ƽ��������ϵ
��������Ϊ�����δ�0�ȵ�180�ȱ仯�Ĺ����У������е㸲�ǣ�����϶�����һ����С��ֵ����һ��͹��������˿��������ַ������������һ���ѵ������֪���������x,y���꣬����������������ƽ���ߣ�ƽ���߲���x���d�ȵĽǣ���ô�������ƽ���ߵľ��롣
	  d1 = fabs(cos(d)*(yi-yj)-sin(d)*(xi-xj));
	  d2 = fabs*(sin(d)*(yi-yj)+cos(d)*(xi-xj));
	  Ϊʲô�������������أ�
	  ��Ϊ�����������������ƽ���ߣ�һ������x���d�Ƚǣ���һ������x�ɣ�180-d���Ƚ� 
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
