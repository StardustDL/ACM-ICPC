/*
Blocks
题意：用四种颜色的漆料去粉刷N盒子，求使红色和绿色盒子数量为偶数的方案的个数。
分析：两种方法
		用dp[N][4]来表示N块砖块的染色情况，一共有四种状态。
		1.dp[N][0] ：表示N块中红色绿色的数量均为偶数。
		2.dp[N][1] ：表示N块中红色为偶数，绿色为奇数。
		3.dp[N][2] ：表示N块中红色为奇数，绿色为偶数。
		4.dp[N][3] ：表示N块中红色绿色的数量均为奇数。
		而状态转移方程为：
			dp[N+1][0] = 2 * dp[N][0] + 1 * dp[N][1] + 1 * dp[N][2] + 0 * dp[N][3]
			dp[N+1][1] = 1 * dp[N][0] + 2 * dp[N][1] + 0 * dp[N][2] + 1 * dp[N][3]
			dp[N+1][2] = 1 * dp[N][0] + 0 * dp[N][1] + 2 * dp[N][2] + 1 * dp[N][3]
			dp[N+1][3] = 0 * dp[N][0] + 1 * dp[N][1] + 1 * dp[N][2] + 2 * dp[N][3]
		上述的转移方程可以转化为矩阵：
			|2 1 1 0|
			|1 2 0 1|
			|1 0 2 1|
			|0 1 1 2| 
		组合数学：
			如果没有限制，一共有4 ^ n 次。现在考虑有 k 块被染为红色或绿色，且在k块中，一定有红色或绿色或两者均为奇数的情况。将这些情况减去，即是想要的答案。（1<= k <= n）
			从n块中选择k块，为c(n, k)。 而从k块中选择不符合的情况染色，需要对k进行奇偶讨论。
			如果k为奇数，红色和绿色的数量为一奇一偶：2 * （c(k, 1) + c(k, 3) +  c(k, 5) +……）* c(n, k) * 2^(n - k)   （其中要乘以2，是因为可以分别选择红、绿色为奇数）
			如果k为偶数，红色和绿色的数量全部为奇数： （c(k, 1) +  c(k, 3) + c(k, 5) +……）* c(n, k) * 2^(n - k) （这里不需要乘以2）
			而  c(k, 1) +  c(k, 3) + c(k, 5) +…… = 2^（k - 1)
			所以，最后的表达式为：
			4^n - 2^n*c(n, 1) - 2^(n - 1)*c(n, 2) - 2^n*c(n, 3) - 2^(n-1)*c(n, 4)-…… = 4^n - 2^n*2^(n-1) - 2^(n-1)*(2^(n-1)-1) = 4^(n-1) + 2^(n-1)
*/
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000,MOD=10007;
struct Matrix{
	int n,m,dat[5][5];
	Matrix(int n,int m):n(n),m(m){
		memset(dat,0,sizeof(dat));
	}
	Matrix operator * (const Matrix &M)const{
		Matrix C=Matrix(n,M.m);
		for(int k=1;k<=m;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=M.m;j++)
					(C.dat[i][j]+=dat[i][k]*M.dat[k][j])%=MOD;
		return C;
	}
};
void ksm(Matrix &S,Matrix a,int n){
	while(n>0){
		if(n&1)S=S*a;
		a=a*a;
		n>>=1;
	}
}
Matrix S=Matrix(4,4),K=Matrix(1,4),ans=Matrix(0,0);
int start[4][4]={{2,1,1,0},{1,2,0,1},{1,0,2,1},{0,1,1,2}};
int n;
int main(){
	for(int i=1;i<=4;i++)memcpy(S.dat[i]+1,start[i-1],sizeof(start[i-1]));
	K.dat[1][1]=1;
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n); 
		ans=K;
		ksm(ans,S,n);
		printf("%d\n",ans.dat[1][1]);
	}
	return 0;
}*/ 
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD=10007;
int ksm(int a,int n){
	int ans=1;
	while(n){
		if(n&1)(ans*=a)%=MOD;
		(a*=a)%=MOD;
		n>>=1;
	}
	return ans;
}
int main(){
	int T,n;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%d\n",(ksm(4,n-1)+ksm(2,n-1))%MOD); 
	}
}


