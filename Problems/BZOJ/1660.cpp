/*
[Usaco2006 Nov]Bad Hair Day �ҷ���
����������ջ��ע����n��ǰ��1�ں󣬲���Ҫ��long long 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL; 
const int MAXN=80000,INF=0x3f3f3f3f;
int n,sta[MAXN+3],tp=0;
LL sum=0;
int main(){
	scanf("%d",&n);
	for(int x,i=1;i<=n;i++){
		scanf("%d",&x);
		while(tp&&sta[tp]<=x)tp--;
		sum+=tp;
		sta[++tp]=x;
	}
	printf("%lld\n",sum);
	return 0;
}

