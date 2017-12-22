/*
[Usaco2008 Oct]建造栅栏
分析：四边形的条件：任意三边之和大于第四边，也就是任意一条边的长度都是小于边长之和的一半
	  所以递推：cnt[i][j]表示前i条边，组成总长度为j的答案数：cnt[i][j]=sigma(cnt[i-1][j-k]|k可行即k<=j&&k<边长和一半，注意不能等于边长和一半，所以下文m=(n+1)/2-1 
*/
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXN=2500;
int n,cnt[5][MAXN+3],m;
int main(){
	scanf("%d",&n);m=(n+1)/2-1;
	cnt[0][0]=1;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=min(j,m);k++)
				cnt[i][j]+=cnt[i-1][j-k];
		}
	}
	printf("%d\n",cnt[4][n]);
	return 0;
}
