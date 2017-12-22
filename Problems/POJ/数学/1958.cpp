/*
���⣺4����hanoi������n<=12�������ٲ�����
������3���ӵ�hanoi��������2^n-1�����и����ĸ��Ľ���˼·����dp��⣬����˵�Ȱ�n�ֳ������֣�A������4���ӷ���Ų��2���ӣ�B������3���ӷ�Ų��4���ӣ�Ȼ����4���ӷ���AŲ��4���ӡ�����B������k������g[i] = g[i - j] * 2 + f[j];
	  g[i]��ʾ4���ӷ���f[i]��3���ӷ���Ų��i�����ӵĲ����� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int g[15]={0},f[15];
int main(){
	f[0]=g[0]=0;
	for(int i=1;i<=12;i++)f[i]=(1<<i)-1;
	for(int i=1;i<=12;i++){
		g[i]=INF;
		for(int j=0;j<=i;j++)g[i]=min(g[i],(g[i-j]<<1)+f[j]);
		printf("%d\n",g[i]);
	}
	return 0;
}

