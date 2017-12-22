/*
sumsets
分析：分有1和没有1讨论，由于必须是2的幂，所以对于奇数的情况，有opt[i]=opt[i-1](分出一个1)
	  对于偶数的情况，有opt[i]=opt[i/2]+opt[i-1](分出一个1，或所有项乘以2)
	  先写的dfs，以为不一定计算所有的opt值，但其实由于都要计算opt[i-1]，所以这样是没有任何改进的
	  而且会爆栈，刚开始还没有mod。。。 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f,MOD=1000000000;
int opt[MAXN+3],n;
int main(){
	cin>>n;
	opt[0]=1;
	for(int i=1;i<=n;i++){
		if(i&1)opt[i]=opt[i-1];
		else opt[i]=(opt[i-1]+opt[i>>1])%MOD;
	}
	cout<<opt[n]<<endl;
	return 0;
}

