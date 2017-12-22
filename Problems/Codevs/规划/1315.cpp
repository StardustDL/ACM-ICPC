/*
�ڻ�
���������ƶ��ر���������������Ʒ�����ı���
	  opt[i][j]��ʾǰi����Ʒ������j������ķ�����
	  ����opt[i][j]=sum{opt[i-1][j-k]|0<=k<=min(j,i��Ʒ����)} 
	  ע��߽�opt[i][0]=1��j��1��ʼö�� 
	  ����һ�֣�opt[0][0]=1��j��0��ʼö�٣�����opt[i][0]һֱΪ0�� 
*/
#include<iostream>
using namespace std;
const int MOD=1000007,MAXN=100;
int n,m,a[MAXN+3],opt[MAXN+3][MAXN+3];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<=n;i++)opt[i][0]=1; 
	for(int i=1;i<=n;i++){//ö����Ʒ 
		for(int j=1;j<=m;j++){//ö������ 
			for(int k=0;k<=min(j,a[i]);k++){//ö��װ���������0��ʼ 
				opt[i][j]=(opt[i][j]+opt[i-1][j-k])%MOD;
			}
		}
	}
	cout<<opt[n][m];
	return 0;
}
