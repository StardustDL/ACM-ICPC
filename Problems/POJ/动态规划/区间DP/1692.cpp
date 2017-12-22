/*
Crossed Matchings
题意：给出两行数，求上下匹配的最多组数是多少。 
		匹配规则 
		1.匹配对的数字必须相同 
		2.每个匹配必须有且只能有一个匹配与之相交叉，且相交叉的两组匹配数字必须不同 
		3.一个数最多只能匹配一次 
分析：opt[i][j]表示A[1..i]匹配B[1..j]的最优解，针对A[i],B[j]的匹配问题，有以下情况：
		 不匹配A[i]或B[j]或者A[i]==B[j]，无法匹配：opt[i][j]=max(opt[i-1][j],opt[i][j-1])
		 A[i]!=B[j]试图匹配：那么在A中从i向前找第一个t1，使得A[t1]==B[j]，匹配A[t1]--B[j]，同理匹配B[t2]--A[i]，
		 这一定是相交的，并且由于是从i,j向前，保证了子问题的性质 
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

