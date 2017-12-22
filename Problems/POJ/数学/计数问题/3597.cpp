/*
题意：把一个多边形划分成仅有3边型和4边型。，问有多少种划分方法。 
分析：设点号为1~n，那么第一条边（端点为1和n），只有：1：构成三角形，2：构成四边形。
	  设X[i]为划分i边型的答案， Y[i]表示第一条边构成三角形的答案数，Z[i]表示第一条边构成四边形的答案数。
		这两种情况的和即为答案。即X[i] = Y[i]+Z[i]。
	  对于三角形，已经确定1和n两个点，只需在2到n-1号点再选一个即可。
	  假设选了j号点（2<=j<=n - 1)，连接1和j，j和n，那么这个三角形把这个n多边型划分成了三部分。
		第一部分。从1点到j点的多边形，边数是j，有X[j]种情况，注意边界情况(j = 2时，边数定义为2，且x[2] = 1）
		第二部分：1，n，j三点构成的三角形。1种情况。
		第三部分：j到n构成的多边形，边数为n-j+1.X[n-j+1]种情况。
	  那么，Y[n] = sigema(X[j] * X[n - j+1])  (2 <= j <= n - 1)。
	  对于四边形，只需在2~n-1号点再选2个点即可。
		第一个点选为j，易知2 <= j <= n - 2（不能选n - 1，否则第二个点就没得选了)。
		连接1和j，构成第一部分，同上，则1~j的边数为j。这个j边形的答案是X[j]。
		接下来不考虑第一部分，
		从j+1 到 n - 1选择第二个点k，连接j和k, k和n，把剩余的部分分成了3个部分，
		j~k部分，边数k - j+1，情况X[k - j + 1]
		四边形1，n，j，k部分，情况1.
		k~n部分，n-k+1条边，情况X[n - k + 1]。
		这三部分的情况数：sigema(X[k - j + 1] * X[n - k + 1]) (j + 1 <= k <= n - 1)
		设k - j + 1 = m；
		sigema(X[m] * X[(n - j + 1) - m + 1]) (2 <= m <= n - j)= Y[n - j + 1] 转化成了第一个问题。
		所以Z[n] = sigema(X[j] * Y[n - j + 1]), 2 <= j <= n - 2.
	  所以X[n] = Y[n]+Z[n].
	  O(n^2)的复杂度。
		PS， 至于模2^64, 由于最大的整数只有这么大，所以用这个类型的无符号形态直接运算就行了，越界了自动从0开始，和模的效果一样，不用再考虑了。
*/
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ULL;
ULL x[50005],y[50005],z[50005];
void init(){
	y[3]=x[3]=x[2]=x[1]=x[0]=1;
	for(int i=4;i<=5000;i++){
		x[i]=0;
		for(int j=2;j<i;j++)y[i]+=x[j]*x[i-j+1];
		for(int j=2;j<i-1;j++)z[i]+=x[j]*y[i-j+1];
		x[i]=y[i]+z[i];
	}
}
int main(){
	init();int n;
	while(scanf("%d",&n)!=EOF)cout<<x[n]<<'\n';
	return 0;
}
