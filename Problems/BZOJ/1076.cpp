/*
[SCOI2008]奖励关
分析：状压，这题数据小，不用判断不可行状态，所以倒推更方便，不用记录状态是否可行，而且答案就是f[1][0] 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
double f[105][(1<<15)+5];
int k,n,v[20],d[20],bin[20];
int main(){
	bin[0]=1;for(int i=1;i<20;i++)bin[i]=bin[i-1]<<1;
	scanf("%d%d",&k,&n);
	for(int i=1,t;i<=n;i++){
		scanf("%d%d",&v[i],&t);
		while(t){d[i]+=bin[t-1];scanf("%d",&t);}
	}
	for(int i=k;i>=1;i--){
		for(int st=0;st<bin[n];st++){
			for(int j=1;j<=n;j++){
				if((st&d[j])==d[j])f[i][st]+=max(f[i+1][st|bin[j-1]]+v[j],f[i+1][st]);
				else f[i][st]+=f[i+1][st];//注意这里，期望=所有物品下的得分和/物品个数，不能取得物品也是有“得分”的 
			}
			f[i][st]/=n;
		}
	}
	printf("%.6lf\n",f[1][0]);
	return 0;
}

