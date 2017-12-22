/*
生日蛋糕
分析：二维背包，暴力DP即可
	  注意一开始要赋成负无穷，赋成-1是不对的 
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
	if(opt[K][V]>0)printf("%d",opt[K][V]);//不要判断==-INF,可能会稍有变化（加了一些数） 
	else puts("impossible");
	return 0;
}

