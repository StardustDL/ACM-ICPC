/*
Piggy-Bank
���⣺����һ������޿յģ�������������Ȼ���������Ӳ�ҵļ�ֵ�Ͷ�Ӧ��������Ҫ����Ƴ����������Ӳ�Ҽ�ֵ����СΪ���٣�ע��Ҫ��֤������ǡ��Ϊ������������
��������ȫ������ע��Ҫװ�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=500,MAXV=10000;
int V,v,w,opt[MAXV+3],T,n; 
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d%d%d",&w,&V,&n);V-=w;
		memset(opt,INF,sizeof(opt));opt[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&w,&v);
			for(int j=v;j<=V;j++)
				if(opt[j-v]!=INF)opt[j]=min(opt[j],opt[j-v]+w);
		}
		if(opt[V]==INF)puts("This is impossible.");
		else printf("The minimum amount of money in the piggy-bank is %d.\n",opt[V]);
	}
	return 0;
}

