/*
序列探秘
分析：设f[i]表示以数值i结尾的序列的长度，f[i]=f[i-k]+1 只要按照读入的顺序f[i]数组中最大的就是结果
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=200010,INF=0x3f3f3f3f;
int n,opt[2*MAXN+3],k,*f=&opt[MAXN],ans=0,t;
int main(){
	scanf("%d%d",&n,&k);
	while(n--){
		scanf("%d",&t);
		ans=max(ans,f[t]=max(f[t],f[t-k]+1));
	}
	printf("%d\n",ans);
	return 0;
}

