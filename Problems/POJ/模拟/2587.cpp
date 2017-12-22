/*
Airline Hub
��Ŀ�����������ϵ�n�������ľ��Ⱥ�γ�ȣ�����������ȷ��һ��HUBʹ������������������������С��
���������㼸�Ρ��������ϵ����Ϊ���ݲ���ֱ��ö�ټ��ɣ��Ƚ�ʱ����Բ�Ľǿ�����߼���Ч�ʣ������ƾ��ȡ�
        ���ù�ʽ��ֱ�ӽ������Ŀռ�Բ�Ľǣ�acos(cos(lat1)*cos(lat2)*cos(lon1-lon2)+sin(lat1)*sin(lat2))��
        ��Ϊ���Ǵ�����꣬��������һ��ɣ��Ƶ��������£�
            ��ͼ��C��DΪ��֪�������������Ƶ���            
            AB = r*cos(lat1)��DE = r*cos(lat2)��BE = r*sin(lat1) + r*sin(lat2)��
            AD*AD = BE*BE + (AB-DE)*(AB-DE) = 2*r*r - 2*r*r*sin(lat1)*sin(lat2) - 2*r*r*cos(lat1)*cos(lat2)��
            AC*AC = 2*AB*AB - 2*AB*AB*cos(lon1-lon2) = 2*r*r*cos(lat1)*cos(lat1)*(1-cos(lon1-lon2))��
            DF*DF = 2*DE*DE - 2*DE*DE*cos(lon1-lon2) = 2*r*r*cos(lat2)*cos(lat2)*(1-cos(lon1-lon2))��
            AC*DF = 2*r*r*cos(lat1)*cos(lat2)*(1-cos(lon1-lon2))��
            �������ܶ����� AC*DF + AD*AD = CD*CD �����У�
            CD = r*sqrt(2-2*(cos(lat1)*cos(lat2)*cos(lon1-lon2)+sin(lat1)*sin(lat2)))��
            ��Բ�Ľ�Ϊ����
            cos(0.5*��) = 0.5*CD/r = sqrt(0.5-0.5*(cos(lat1)*cos(lat2)*cos(lon1-lon2)+sin(lat1)*sin(lat2)))��
            cos(0.5*��)*cos(0.5*��) = 0.5 - 0.5*(cos(lat1)*cos(lat2)*cos(lon1-lon2)+sin(lat1)*sin(lat2))��
            cos�� = 1 - 2*cos(0.5*��)*cos(0.5*��) = cos(lat1)*cos(lat2)*cos(lon1-lon2)+sin(lat1)*sin(lat2)��
            Բ�Ľ�Ϊ��acos(cos(lat1)*cos(lat2)*cos(lon1-lon2)+sin(lat1)*sin(lat2))��
		ע�⾫�ȿ��ơ�
	  ������ http://blog.csdn.net/mobius_strip/article/details/12731459 
	  ��˵ֱ�߾���Ҳ��AC�����Ҳ��Է��ֲ��� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#define sqr(x) ((x)*(x))
using namespace std;
const int MAXN=1000;
const double eps=1e-6,INF=1e20;
int n,p=0;
double x[MAXN+3],y[MAXN+3],ans=INF,dis[MAXN+3][MAXN+3];
double dist( double l1, double d1, double l2, double d2 ){  
    double p = acos(-1.0);  
    l1 *= p/180.0; d1 *= p/180.0;   
    l2 *= p/180.0; d2 *= p/180.0;   
    return acos(cos(l1)*cos(l2)*cos(d1-d2)+sin(l1)*sin(l2)); 
    //return sqr(l1-l2)+sqr(d1-d2);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&x[i],&y[i]);
	for(int i=1;i<=n;i++){
		double t=0,k;
		for(int j=1;j<=n;j++)
			if(t<(k=dist(x[i],y[i],x[j],y[j])))t=k;//�������min�����ͻ�WA 
		if(ans>t){ans=t;p=i;}
	}
	printf("%.2lf %.2lf\n",x[p],y[p]);
	return 0;
}

