/*
[HNOI2006]�����ӵ�ħ��
�������۲�һά�������ÿ����һ���߶���������������䣨�߶������ཻ���������µģ���
		Ȼ���Ƕ�ά����������������ཻ��Բ�����ڼ�������������Է�������ѵ�����Բչ����һ���߶Σ�
		������������Բ�ཻ��λ��Ҳ��Ӧ���߶��ϣ���ô����ת����һά�������߶ε������
		�ɴ˵ó�DP����f[i][j]Ϊ����������������iΪά����jΪʩ�����������̣�f[i][j]=f[i][j-1] + f[i-1][j-1]�� 
		�߽�f[1][i]=2*i,f[i][1]=2 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL cnt[18][103];
int n,m;
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)cnt[1][i]=i*2;
	for(int i=1;i<=n;i++)cnt[i][1]=2;
	for(int i=2;i<=n;i++)
		for(int j=2;j<=m;j++)
			cnt[i][j]=cnt[i][j-1]+cnt[i-1][j-1];
	printf("%lld\n",cnt[n][m]);
	return 0;
}

