/*
Recaman's Sequence
分析：递推即可 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int MAXN=500000;
bitset<20*MAXN+3> vis=0;//注意要大一些 
int ans[MAXN+3],k;
int main(){
	ans[0]=0;vis[0]=1;
	for(int i=1;i<=MAXN;i++){
		if(ans[i-1]-i>0&&!vis[ans[i-1]-i])ans[i]=ans[i-1]-i;
		else ans[i]=ans[i-1]+i;
		vis[ans[i]]=1;
	}
	while(scanf("%d",&k)&&k!=-1)printf("%d\n",ans[k]); 
	return 0;
}

