/*
[Usaco2006 Dec]Cow Roller Coaster
分析：opt[i][j]表示铺到i-1(下次该铺i)，花费为j的最优解
	  注意题目中其实是从0到l-1 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10000,MAXL=1000,INF=0x3f3f3f3f;
struct segment{
	int x,w,f,c;
	bool operator <(const segment &s)const{
		return x<s.x;
	}
}s[MAXN+3];
int opt[MAXL+3][MAXL+3],l,n,b;
int main(){
	scanf("%d%d%d",&l,&n,&b);
	memset(opt,-1,sizeof(opt));
	for(int i=0;i<=b;i++)opt[0][i]=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&s[i].x,&s[i].w,&s[i].f,&s[i].c);
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		for(int j=b-s[i].c;j>=0;j--){
			if(opt[s[i].x][j]==-1)continue;//注意输入数据，这里不要用s[i].x-1 
			opt[s[i].x+s[i].w][j+s[i].c]=max(opt[s[i].x][j]+s[i].f,opt[s[i].x+s[i].w][j+s[i].c]);
		}
	}
	printf("%d",opt[l][b]);
	return 0;
}

