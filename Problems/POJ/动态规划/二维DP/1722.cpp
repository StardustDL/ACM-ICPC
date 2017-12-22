/*
SUBTRACT 
题意：定义一种操作，操作i就是将a[i]-a[i+1]取出进行合并，再加入到a[i]的位置（我自己臆测的题意），进行n-1次操作后，会剩下一个数字。给定a[1]~a[n]及目标t（最后剩下的数字），求操作顺序。
分析：此题相当于在序列之间添加+-两种符号使得答案是t，最后按照+-号输出就是了，PS：第一个符号必定是减号！
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f,R=10000;
int can[MAXN+3][R+3<<1];
bool op[MAXN+3];
int n,T,a[MAXN+3];
int main(){
	scanf("%d%d",&n,&T);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(can,0,sizeof(can));
	can[1][a[1]+R]=1;
	can[2][a[1]-a[2]+R]=-1;
	for(int i=3;i<=n;i++){
		for(int j=0;j<=R<<1;j++){
			if(can[i-1][j]==0)continue;
			if(j+a[i]<=R<<1)can[i][j+a[i]]=1;//加 
			if(j-a[i]>=0)can[i][j-a[i]]=-1;//减 
		} 
	}
	for(int i=n,j=R+T;i>=1;i--){
		op[i]=can[i][j]==1;
		j-=a[i]*can[i][j];
	}
	int cnt=0;
	for(int i=2;i<=n;i++)if(op[i])printf("%d\n",i-cnt-1),cnt++;
	for(int i=2;i<=n;i++)if(!op[i])puts("1");
	return 0;
}

