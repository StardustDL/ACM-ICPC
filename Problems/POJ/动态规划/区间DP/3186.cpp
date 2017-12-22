/*
Treats for the Cows
���⣺������һϵ�е����֣����Կ���һ��˫����У�ÿ��ֻ�ܴӶ��׻��߶�β���ӣ���n�����Ӿ������������n����󽫺ͼ�������������
������a[i]*n���ô���������ת��״̬���壺opt[i][j]��ʾ������������(n-(j-i+1)+1)..n�������е����Ž���a[i]��a[j]���һ�����������Ϳ��Աܿ��������˳�������
	   ת����opt[i][j]=max{opt[i+1][j]+a[i]*(n-len+1),opt[i][j-1]+a[j]*(n-len+1)} 
	   ��ʼ����opt[i][i]=a[i]*(n-1+1) 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=2000;
int opt[MAXN+3][MAXN+3],a[MAXN+3],n; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),opt[i][i]=a[i]*n;
	for(int len=2;len<=n;len++){
		for(int i=1,j;i+len-1<=n;i++){
			j=i+len-1;
			opt[i][j]=max(opt[i+1][j]+a[i]*(n-len+1),opt[i][j-1]+a[j]*(n-len+1));
		}
	}
	printf("%d\n",opt[1][n]);
	return 0;
}

