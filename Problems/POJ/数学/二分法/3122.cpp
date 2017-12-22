/*
Pie
���⣺���գ�����n��pie������f�����ѣ���ô��������f+1��
	  ÿ��pie���Ǹ�Ϊ1��Բ���壬������n��pie��ÿһ���ߴ磨�뾶�������Ҫ��ƽ�ذ�pie�ָ�ÿһ���ˣ����������˵õ���pie�ߴ�һ�£�������״���Բ�ͬ��������ÿ���˵õ����Ƿ�pie�����Ǵ�ͬһ��pie�ϵõ���
���������ִ𰸣�ע�⾫�ȣ�����⾫��Ҫ��� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
const double PI=3.14159265359;
double p[MAXN+3];
int n,f,T;
inline bool check(double val){
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=(int)(p[i]/val);
	return cnt>=f;
}
inline double erfen(double l,double r,double eps){
	double mid,ans=l;
	while(r-l>eps){
		mid=(l+r)/2.0;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	return ans;
}
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d%d",&n,&f);f++;
		for(int i=1,r;i<=n;i++){
			scanf("%d",&r);
			p[i]=r*r;
		}
		printf("%.4lf\n",erfen(0,*max_element(p+1,p+n+1),1e-6)*PI); 
	}
	return 0;
}

