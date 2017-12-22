/*
Apple Catching
���⣺����ƻ����ÿһ�ֻ���������ƻ��������ȥ�ӣ���������������֮��Ĵ�����һ���ģ����������������ʱ����ܽӵ�����ƻ����
����������DP��Ȼ�������ض��ٴ�Ϊ�׶Σ�ʱ��͵�ǰλ��Ϊ״̬���ӵ�������Ϊ״ֵ̬�������������г�ת�Ʒ��̣�
	  ע���ʼ������Ϊ�տ�ʼ����һֱ��ĳһ����һֱ����������Ҫ��ʼ������opt[0][1..T][0..1] 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000,MAXW=30;
int a[MAXN+3][2],opt[MAXW+3][MAXN+3][2],t,w;
int main(){
	scanf("%d%d",&t,&w);
	for(int i=1,j;i<=t;i++){
		scanf("%d",&j);
		a[i][j-1]=1; 
	}
	for(int i=1;i<=t;i++){
		opt[0][i][0]=opt[0][i-1][0]+a[i][0];
		opt[0][i][1]=opt[0][i-1][1]+a[i][1];
	}
	for(int i=1;i<=w;i++){
		for(int j=1;j<=t;j++){
			opt[i][j][0]=max(opt[i-1][j-1][1],opt[i][j-1][0])+a[j][0];
			opt[i][j][1]=max(opt[i-1][j-1][0],opt[i][j-1][1])+a[j][1];
		}
	}
	printf("%d",max(opt[w][t][0],opt[w][t][1]));
	return 0;
}

