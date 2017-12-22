/*
LITTLE SHOP OF FLOWERS
���⣺F��������V��ƿ�����棬��Ҫ����Ų壬��ͬ�����벻ͬ�Ļ�ƿ�в�ͬ�����۳̶ȣ�Ҫ���������۳̶ȡ�
������opt[i][j]��ʾ��i��������ǰj��ƿ�����档��״̬ת�ƺ���Ϊopt[i][j]=max(opt[i-1][j-1]+a[i][j],opt[i][j-1])
	  ��Ϊ�����ֲ巨��һ����i���������j��ƿ�����棬��Ϊopt[i][j]=opt[i-1][j-1]+a[i][j].������i�����������j��ƿ�����棬��opt[i][j]=opt[i][j-1]��
	  ��ʼ��Ҳ����Ҫ������opt[i][i]ֻ�����β� 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100;
int f,v,a[MAXN+3][MAXN+3],opt[MAXN+3][MAXN+3];
int main(){
	cin>>f>>v;
	for(int i=1;i<=f;i++)
		for(int j=1;j<=v;j++)cin>>a[i][j];
	for(int i=1;i<=v;i++)opt[i][i]=opt[i-1][i-1]+a[i][i];
	for(int i=1;i<=f;i++)
		for(int j=i+1;j<=v;j++)
			opt[i][j]=max(opt[i][j-1],opt[i-1][j-1]+a[i][j]);
	cout<<opt[f][v];
	return 0;
} 
