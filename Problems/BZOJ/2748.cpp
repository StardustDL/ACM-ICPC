/*
[HAOI2012]音量调节
分析：直接背包DP 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXL=1000,INF=0x3f3f3f3f;
bool can[2][MAXL+3];
int begin,maxl,n,c,cur=0; 
int main(){
	scanf("%d%d%d",&n,&begin,&maxl);
	can[cur=0][begin]=1;
	for(int i=1;i<=n;i++,cur^=1){
		scanf("%d",&c);
		memset(can[cur^1],0,sizeof(can[cur^1]));
		for(int j=0;j<=maxl;j++)
			can[cur^1][j]=j-c>=0&&can[cur][j-c] || j+c<=maxl&&can[cur][j+c];
	}
	while(maxl>=0&&can[cur][maxl]==0)maxl--;
	printf("%d",maxl<0?-1:maxl);
	return 0;
}

