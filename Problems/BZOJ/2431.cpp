/*
[HAOI2009]���������
������f[i][j]��ʾֻ��ǰ1~i����Ȼ����ɵ������У�����Ը���Ϊj�ķ�������
		������δ�f[i-1]ת�Ƶ�f[i]��f[i-1]��ʾһ��ֻ����1~i-1�����У��������Ǽ���һ������i����Ȼԭ����������������iС������i�����λ�þ;����������ӵ�����Ը�����
		f[i][j]=sigma{f[i-1][k]|k=[0..min(i-1,j)]}��ǰ׺���Ż� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f,MOD=10000;
int f[MAXN+3],g[MAXN+3],n,K;
int main(){
	scanf("%d%d",&n,&K);
	g[0]=1;for(int j=1;j<=K;j++)g[j]=g[j-1]+f[j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=K;j++)
			f[j]=((g[j]-g[j-min(i-1,j)-1])%MOD+MOD)%MOD;
		for(int j=1;j<=K;j++)g[j]=(g[j-1]+f[j])%MOD;
	}
	printf("%d\n",f[K]);
	return 0;
}

