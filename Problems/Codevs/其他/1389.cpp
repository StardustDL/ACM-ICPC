/*
�˻�ƽ����
������ֱ��ģ�⣬ע��Ҫ���Ͽ�n�η�����������ٿ�������õ�inf
	  (a*b)^(1/n)=a^(1/n)*b^(1/n)
*/
#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
double ans=1;
int n,t;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t;ans*=pow(t,1.0/n);
	}
	//ans=pow(ans,1.0/n);
	printf("%.2lf",ans);
	return 0;
}
