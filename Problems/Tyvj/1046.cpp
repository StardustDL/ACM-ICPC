/*
Blast
������DP��opt[i][j]��ʾa��ǰi����b��ǰj������̾���
		����opt[i][0]=i*k,opt[0][i]=i*k,
		opt[i][j]=min{opt[i-1][j]+k,opt[i][j-1]+k,opt[i-1][j-1]+abs(a[i]-b[j])} 
		���־��ߣ�		b��һ���ո� a��һ���ո�		a,b�����ſո� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
char a[MAXN+3],b[MAXN+3];
int k,la,lb,opt[MAXN+3][MAXN+3]; 
int main(){
	scanf("%s%s%d",a,b,&k);
	la=strlen(a);lb=strlen(b);
	for(int i=1;i<=la;i++)opt[i][0]=i*k;
	for(int i=1;i<=lb;i++)opt[0][i]=i*k;
	for(int i=1;i<=la;i++){
		for(int j=1;j<=lb;j++){
			opt[i][j]=min(min(opt[i][j-1],opt[i-1][j])+k,opt[i-1][j-1]+abs(a[i-1]-b[j-1]));
		}
	}
	printf("%d\n",opt[la][lb]);
	return 0;
}

