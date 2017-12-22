/*
[BeiJing2011集训]星器
分析：答案与移动方法无关（因为有行列限制并且是2个同时在同行同列移动，这样，只要这行这列有个点是终点，无论是怎么累计起来的，能到达的点到这里的距离和相等）
		在矩形中，对角线的距离是不会变的。而且我们要充分挖掘它的性质。我们将这个矩形放到每个点来看，原矩形的左上角到每个点的矩阵
		首先我们假设两个点(i,j),(i,k)向中间移动一格，且k>j+1，那么我们可以获得的价值为k-j，这样，我们定义每个点的每个星的能量为 a[(i,j)]=i*i+j*j，这样这两个点开始的能量为i*i+j*j+i*i+k*k，移动之后，两个点变为(i,j+1),(i,k-1)，这 时的能量为i*i+(j+1)*(j+1)+i*i+(k-1)，这时的能量差为2*k-2*j，为获得价值的2倍，因为对于所有的价值获得都可以采用这样的方法，所以我们可以算出开始局面的能量和，结束局面的能量和，相减>>1就是答案。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200,INF=0x3f3f3f3f;
typedef long long LL;
int n,m;
LL s1,s2;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1,x;j<=m;j++){
			scanf("%d",&x);
			s1+=((i*i)+(j*j))*x;
		}
	for(int i=1;i<=n;i++)
		for(int j=1,x;j<=m;j++){
			scanf("%d",&x);
			s2+=((i*i)+(j*j))*x;
		}
	printf("%lld\n",s1-s2>>1);
	return 0;
}

