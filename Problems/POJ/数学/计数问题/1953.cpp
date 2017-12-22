/*
World Cup Noise
���⣺�������Ϊn��01���У�����������1�Ĵ��ĸ���
��������=���һλΪ0�����ָ����������һλΪ1�����ָ�����
	  ����ǰһλҪ����1��ǰһλ���ֻ����0����ǰһλҪ����0��ǰһλ������Ϊ 1��Ҳ����Ϊ0��
	  ��O[i]��Z[i]�ֱ��ʾiλ�������һλΪ0���������һλΪ1������f[i]��ʾiλ������������f[i] = O[i] + Z[i]���������Ϸ�����O[k] = Z[k-1] = O[k-2] + Z[k-2] = f[k-2], Z[k] = O[k-1] + Z[k-1] = f[k-1], So f[k] = O[k] + Z[k] = f[k-1] + f[k-2]��
	  �ⲻ����쳲�����������f[1] = 2, f[2] = 3, f[k] = f[k-1] + f[k-2]��
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=45;
int fib[MAXN+3],n,T;
int main(){
	fib[0]=1;fib[1]=2;
	for(int i=2;i<=MAXN;i++)fib[i]=fib[i-1]+fib[i-2];
	scanf("%d",&T);
	for(int i=1;i<=T;i++){scanf("%d",&n);printf("Scenario #%d:\n%d\n\n",i,fib[n]);}
	return 0;
}

