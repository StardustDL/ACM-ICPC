/*
[Usaco2005 Jan]Sumsets ���
��������1<<iΪ��Ʒ������ȫ����
	  ����opt[i][j]��ʾi��<=2^j������ϵķ�������opt[i][j]=sum{opt[i-k*(1<<j)][j-1]|i-k*(1<<j)>=0}
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f,MOD=1000000000;
#define Mod(x) ((x)%=MOD)
int n,cnt[MAXN+3];
int main(){
	scanf("%d",&n);
	cnt[0]=1;
	for(int i=0;(1<<i)<=n;i++)
		for(int j=(1<<i);j<=n;j++)
			Mod(cnt[j]+=cnt[j-(1<<i)]);
	printf("%d\n",cnt[n]);
	return 0;
}

