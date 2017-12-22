/*
Treats for the Cows
题意：给出的一系列的数字，可以看成一个双向队列，每次只能从队首或者队尾出队，第n个出队就拿这个数乘以n，最后将和加起来，求最大和
分析：a[i]*n不好处理，但可以转换状态定义：opt[i][j]表示此区间在最后第(n-(j-i+1)+1)..n个出队列的最优解且a[i]或a[j]最后一个出，这样就可以避开这个出队顺序的限制
	   转移是opt[i][j]=max{opt[i+1][j]+a[i]*(n-len+1),opt[i][j-1]+a[j]*(n-len+1)} 
	   初始化：opt[i][i]=a[i]*(n-1+1) 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=2000;
int opt[MAXN+3][MAXN+3],a[MAXN+3],n; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),opt[i][i]=a[i]*n;
	for(int len=2;len<=n;len++){
		for(int i=1,j;i+len-1<=n;i++){
			j=i+len-1;
			opt[i][j]=max(opt[i+1][j]+a[i]*(n-len+1),opt[i][j-1]+a[j]*(n-len+1));
		}
	}
	printf("%d\n",opt[1][n]);
	return 0;
}

