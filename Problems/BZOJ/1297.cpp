/*
[SCOI2009]迷路
题意：给定一个邻接矩阵，求1~n的边权恰好为T的路径条数，边权[1..9]
	  考虑当所有边权都是1的时候 那么显然邻接矩阵自乘T次之后a[1][n]就是答案
		因为当边权为1的时候a[i][j]可以表示从第i个点转移到第j个点的方案数 显然这个符合矩乘的定义
		现在边权最大为9 那么将一个点拆成9个 第i个点拆成的第j+1个点向第j个点连一条边权为1的边 
		那么i->j有一条边权为k的边等价于i向j拆成的第k个点连边 
		这样拆点不仅相当于是把边变成了点，同时保证了点的规模仍是O(n)的。
	  注意矩阵乘维护n,m，注意单位矩阵 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f,MOD=2009;
int n,t;
struct matrix{
	int d[10*10][10*10];
	int n,m;
	int* operator [](int x){return d[x];}//一个小技巧 
	void clear(){memset(d,0,sizeof(d));}
}mp,temp,Ans;
void multiply(matrix &a,matrix &b,matrix &c){
	c.clear();c.n=a.n;c.m=b.m;
	for(int i=1;i<=a.n;i++)
		for(int j=1;j<=b.m;j++)
			for(int k=1;k<=a.m;k++)
				(c[i][j]+=a[i][k]*b[k][j])%=MOD;
}
void quickpow(matrix &a,matrix &ans,int n){
	while(n){
		if(n&1){multiply(ans,a,temp);ans=temp;}
		n>>=1;
		multiply(a,a,temp);a=temp;
	}
}
#define P(x,y) ((y-1)*n+x)
int main(){
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
		for(int j=2;j<=9;j++)mp[P(i,j)][P(i,j-1)]=1;
	for(int i=1;i<=n;i++){
		for(int j=1,k;j<=n;j++){
			scanf("%1d",&k);
			if(k==0)continue;
			mp[i][P(j,k)]=1;
		}
	}
	mp.n=mp.m=Ans.n=Ans.m=9*n;
	for(int i=1;i<=9*n;i++)Ans[i][i]=1;
	quickpow(mp,Ans,t);
	printf("%d\n",Ans[1][n]);
	return 0;
}

