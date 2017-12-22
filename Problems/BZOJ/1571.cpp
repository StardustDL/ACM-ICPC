/*
[Usaco2009 Open]滑雪课Ski
分析：令f[i][j]表示时间为i，能力为t的最优解，那么有三种转移
	  f[i][j]=f[i-1][j]
	  		  f[课程开始][任意能力]
			  f[i-某滑雪时间][j]     <能力满足>
		预处理在同一时间结束的能力相同的课程中最晚开始的和满足滑雪能力a的最短滑雪时间（这一定最优）
		然后令g[i]=max{f[i][j]}，这样第二个转移就O(1)了 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
int f[MAXN+3][100+3],g[MAXN+3],les[MAXN+3][100+3],ski[100+3],T,s,n;
int main(){
	scanf("%d%d%d",&T,&s,&n);
	memset(f,128,sizeof(f));//赋极小值，-2139062144，乘2会爆成正的 
	memset(ski,INF,sizeof(ski));
	for(int i=1,a,b,c;i<=s;i++){
		scanf("%d%d%d",&a,&b,&c);
		les[a+b-1][c]=max(les[a+b-1][c],a);
	}
	for(int i=1,a,b;i<=n;i++){
		scanf("%d%d",&a,&b);
		for(int j=a;j<=100;j++)ski[j]=min(ski[j],b);
	}
	f[0][1]=0;g[0]=0; 
	for(int i=1;i<=T;i++){
		for(int j=1;j<=100;j++){
			f[i][j]=f[i-1][j];
			if(les[i-1][j])f[i][j]=max(f[i][j],g[les[i-1][j]]);
			if(ski[j]&&i-ski[j]>=0)f[i][j]=max(f[i][j],f[i-ski[j]][j]+1);
			g[i]=max(g[i],f[i][j]);
		}
	}
	printf("%d\n",g[T]);
	return 0;
}
