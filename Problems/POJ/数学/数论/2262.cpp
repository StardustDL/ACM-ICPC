/*
Goldbach's Conjecture
���⣺��1000000�ڵ�ż�����и�°ͺղ���
������ɸ��������Ȼ������ע��ɸ��ʱ�ᱬint 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000000;
typedef long long LL;
bitset<MAXN+3> isp=0;
int k,i;
int main(){
	for(i=2;i<=MAXN;i++){
		if(isp[i])continue;
		for(LL j=((LL)i)*i;j<=MAXN;j+=i)isp[j]=1;
	}
	while(scanf("%d",&k),k){
		for(i=3;i<(k>>1);i++){
			if((!isp[i])&&(!isp[k-i]))break;
		}
		printf("%d = %d + %d\n",k,i,k-i);
	}
	return 0;
}

