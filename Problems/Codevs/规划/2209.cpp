/*
��Ԫ=doller=��=knife
������������DP���������̰�ľ͹��ˣ�������
	  ̰�ĵ�˼·�ǣ��Ƚ����ڵ����죬���(ǰһ��/����)>1����ô�Ͷһ���ʵ�����൱�ڶһ������Σ�
	  ��ȷ����ô֤���أ� 
*/
#include<iostream>
#include<cstdio>
using namespace std;
int a,b,n;
double ans=100.0;
int main(){
	cin>>n>>a;
	n--;
	while(n-->0){
		cin>>b;
		if(a>b)ans*=a*1.0/b;
		a=b;
	}
	printf("%.2lf",ans);
	return 0;
}
