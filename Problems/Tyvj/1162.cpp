/*
���յ���
��������ά����������DP����
	  ע��һ��ʼҪ���ɸ��������-1�ǲ��Ե� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=200,MAXK=20,MAXV=1000,INF=0x3f3f3f3f;
int opt[MAXK+3][MAXV+3],N,K,V,v[MAXN+3],c[MAXN+3]; 
int main(){
	scanf("%d%d%d",&K,&V,&N);
	for(int i=1;i<=N;i++)scanf("%d%d",&v[i],&c[i]);
	memset(opt,-INF,sizeof(opt));
	opt[0][0]=0;
	for(int i=1;i<=N;i++){
		for(int j=K;j>=1;j--){
			for(int k=V;k>=v[i];k--){
				opt[j][k]=max(opt[j-1][k-v[i]]+c[i],opt[j][k]);
			}
		}
	}
	if(opt[K][V]>0)printf("%d",opt[K][V]);//��Ҫ�ж�==-INF,���ܻ����б仯������һЩ���� 
	else puts("impossible");
	return 0;
}

