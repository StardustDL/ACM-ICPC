/*
�ǹ�
������ԭ��������������C(n-1,k)
	  �����������ԣ����ظ�������Ҳ��α�ˡ�����
	  ��ʵ�������Ļ��� 
*/ 
#include<iostream>
using namespace std;
const int MAXN=60000,MAXK=100,MOD=10000;
int opt[MAXN+3][MAXK+3],n,k;
int main(){
	cin>>n>>k;
	opt[0][0]=1; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)
			if(i>=j)opt[i][j]=(opt[i-1][j-1]+opt[i-j][j])%MOD;
	}
	cout<<opt[n][k];
	return 0;
}
