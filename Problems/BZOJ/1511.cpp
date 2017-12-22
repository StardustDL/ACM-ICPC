/*
[POI2006]OKR-Periods of Words
分析：求一个串的所有前缀的最长周期长度之和，特别的，周期为自己的串的最长周期长度视作0. 
 		KMP有个性质i-nxt[i]为 [1..i]的最小周期，那向前找最远的就是最大的了 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
char str[MAXN+3];
int n,nxt[MAXN+3]; 
int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	nxt[0]=0;nxt[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j&&str[j+1]!=str[i])j=nxt[j];
		nxt[i]=str[j+1]==str[i]?++j:0;
	}
	//for(int i=1;i<=n;i++)cout<<nxt[i]<<" ";
	for(int i=1;i<=n;i++){
		if(!nxt[i])continue;
		while(nxt[nxt[i]])nxt[i]=nxt[nxt[i]];
	}
	long long ans=0;
	for(int i=1;i<=n;i++)if(nxt[i])ans+=(i-nxt[i]);
	printf("%lld\n",ans);
	return 0;
}

