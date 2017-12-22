/*
Crossed Matchings
���⣺������������������ƥ�����������Ƕ��١� 
		ƥ����� 
		1.ƥ��Ե����ֱ�����ͬ 
		2.ÿ��ƥ���������ֻ����һ��ƥ����֮�ཻ�棬���ཻ�������ƥ�����ֱ��벻ͬ 
		3.һ�������ֻ��ƥ��һ�� 
������opt[i][j]��ʾA[1..i]ƥ��B[1..j]�����Ž⣬���A[i],B[j]��ƥ�����⣬�����������
		 ��ƥ��A[i]��B[j]����A[i]==B[j]���޷�ƥ�䣺opt[i][j]=max(opt[i-1][j],opt[i][j-1])
		 A[i]!=B[j]��ͼƥ�䣺��ô��A�д�i��ǰ�ҵ�һ��t1��ʹ��A[t1]==B[j]��ƥ��A[t1]--B[j]��ͬ��ƥ��B[t2]--A[i]��
		 ��һ�����ཻ�ģ����������Ǵ�i,j��ǰ����֤������������� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
int opt[MAXN+3][MAXN+3],a[MAXN+3],b[MAXN+3],n,m,T;
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int j=1;j<=m;j++)scanf("%d",&b[j]);
		memset(opt,0,sizeof(opt));
		for(int i=2;i<=n;i++){
			for(int j=2,k1,k2;j<=m;j++){
				opt[i][j]=max(opt[i-1][j],opt[i][j-1]);
				if(a[i]==b[j])continue;
				for(k1=i-1;k1&&a[k1]!=b[j];k1--);
				for(k2=j-1;k2&&b[k2]!=a[i];k2--);
				if(k1&&k2)opt[i][j]=max(opt[i][j],opt[k1-1][k2-1]+2);
			}
		}
		printf("%d\n",opt[n][m]);
	}
	return 0;
}

