/*
[Usaco2008 Oct]����դ��
�������ı��ε���������������֮�ʹ��ڵ��ıߣ�Ҳ��������һ���ߵĳ��ȶ���С�ڱ߳�֮�͵�һ��
	  ���Ե��ƣ�cnt[i][j]��ʾǰi���ߣ�����ܳ���Ϊj�Ĵ�����cnt[i][j]=sigma(cnt[i-1][j-k]|k���м�k<=j&&k<�߳���һ�룬ע�ⲻ�ܵ��ڱ߳���һ�룬��������m=(n+1)/2-1 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN=2500;
int n,cnt[5][MAXN+3],m;
int main(){
	scanf("%d",&n);m=(n+1)/2-1;
	cnt[0][0]=1;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=min(j,m);k++)
				cnt[i][j]+=cnt[i-1][j-k];
		}
	}
	printf("%d\n",cnt[4][n]);
	return 0;
}
