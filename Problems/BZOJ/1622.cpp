/*
[Usaco2008 Open]Word Power 名字的能量
分析：暴力 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
char s[MAXN+3][MAXN+3],t[100+3][30+3];
int n,m,lens[MAXN+3],lent[103],ans[MAXN+3]; 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%s",s[i]);lens[i]=strlen(s[i]);for(int x=0;x<lens[i];x++)s[i][x]=tolower(s[i][x]);}
	for(int i=1;i<=m;i++){scanf("%s",t[i]);lent[i]=strlen(t[i]);for(int x=0;x<lent[i];x++)t[i][x]=tolower(t[i][x]);}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int l=0,r=0;
			while(l<lens[i]&&r<lent[j]){
				if(s[i][l]==t[j][r])r++;
				l++;
			}
			if(r==lent[j])ans[i]++;
		}
	}
	for(int i=1;i<=n;i++)printf("%d\n",ans[i]); 
	return 0;
}

