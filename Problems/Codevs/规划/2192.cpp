/*
ɾ��
���������һ����ֻʣ��һ����ɾ���������飬
	  �����Ѿ�ɾ���������飬����һ���������ˣ�
	  �ֿ��Է�Ϊ���һ��ɾ�ĺ�֮ǰɾ�������֡� 
	  ���Կ������α������һ��ɾ����λ��
	  f[i][j]��ʾ��i��j��ɾ�������ֵ,
	  sum[i][j]��ʾֱ��ɾ����i��j�Ĳ���ֵ
	  f[i][j]=max{max{f[i][k]+f[k+1][j]|i<=k<j},sum[i][j]} 
*/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100;
int n,a[MAXN+3],opt[MAXN+3][MAXN+3];
int dp(){
	for(int i=1;i<=n;i++)opt[i][i]=a[i];//ע��߽� 
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			int &t=opt[i][j];
			for(int k=i;k<j;k++){
				t=max(t,opt[i][k]+opt[k+1][j]);
			}
			t=max(t,abs(a[j]-a[i])*(j-i+1));
		}
	}
	return opt[1][n];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<dp();
	return 0;
}
