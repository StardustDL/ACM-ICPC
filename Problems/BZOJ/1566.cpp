/*
[NOI2009]管道取珠
分析：这是一道非常精致的递推问题，程序非常短，但很难想到。问题的关键是对目标的转化以及递推状态的设计。
		首先对 ∑ai^2 进行转化，将其这样理解：用A和B分别表示一种取珠的方法，将结果相同的两种取珠方法（不管这两种取珠方法本身是否相同）记为(A, B)，不难发现∑ai^2就是所有这样的(A, B)的对数。
		设状态f(a1, b1, a2, b2)，如果f(a1, b1, a2, b2) = K，表示存在K对不完全相同的(A, B)，使得A方法已经取出了第一个串的前a1个字符及第二个串的前b1个字符，B方法已经取出了第一个串的前a2个字符以及第二个串的前b2个字符，同时A方法与B方法得到的结果相同。
		显然，f(a1, b1, a2, b2)可以转移向4个方向：f(a1+1, b1, a2+1, b2)，f(a1+1, b1, a2, b2+1)，f(a1, b1+1, a2+1, b2)，f(a1, b1+1, a2, b2+1)，转移可行的前提是对应的字母相同。
		最后，f(n, m, n, m)就是问题的答案。递推初态是f(0, 0, 0, 0) = 1.
		另外，由于A和B的结果相同，显然有a1+b1 = a2+b2，故只要存储其中的三个值即可。算法的时空复杂度均为O(n3)。空间复杂度经优化可到n^2 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=500,MOD=1024523;
int dp[MAXN+3][MAXN+3][MAXN+3],n,m;
char a[MAXN+3],b[MAXN+3];
inline void add(int &x,int y){
	(x+=y)%=MOD;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s%s",a+1,b+1);
	reverse(a+1,a+n+1);reverse(b+1,b+m+1);
	dp[0][0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=n;k++){
				int l=i+j-k,t=dp[i][j][k];
				if(t==0)continue;
				if(a[i+1]==a[k+1])add(dp[i+1][j][k+1],t);
				if(a[i+1]==b[l+1])add(dp[i+1][j][k],t);
				if(b[j+1]==a[k+1])add(dp[i][j+1][k+1],t);
				if(b[j+1]==b[l+1])add(dp[i][j+1][k],t);
			}
		} 
	} 
	printf("%d\n",dp[n][m][n]);
	return 0;
} 
