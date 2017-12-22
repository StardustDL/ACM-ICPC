/*
题意：有一些汽车在左岸，你要用一条小破船把它们拉到右岸去。每个测试点包含多个测试数据。第一行的整数C表示测试数据的数目。接下来每个测试数据的第一行为三个整数N, T, M表示一次可以运送N辆汽车，到达对岸的时间为T，汽车的总数是M。接下来的M行每行有一个整数，表示这辆汽车什么时候会来到左岸。对于每个测试数据，输出两个整数，分别是最少要耗用多少时间（包括你等车的时间，就是从0开始直到最后一辆车到达右岸），以及在这个前提下你最少要运送多少次。只要到右岸去就算作一次。
分析：先运送M % N辆汽车到对岸（就是M除上N的余数），之后每次运N辆汽车，直到运完为止。这里的意思是，只有船上确实有了这么多车才出发，在此之前等着那些车来。 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1440,INF=0x3f3f3f3f;
int T,m,n,t,opt[MAXN+3],tme[MAXN+3],a[MAXN+3]; 
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d%d%d",&n,&t,&m);
		for(int i=1;i<=m;i++)scanf("%d",&a[i]);
		opt[0]=tme[0]=0;
		for(int i=1;i<=m;i++)opt[i]=max(opt[max(i-n,0)],a[i])+(t<<1),tme[i]=tme[max(i-n,0)]+1;
		printf("%d %d\n",opt[m]-t,tme[m]);
	}
	return 0;
}

