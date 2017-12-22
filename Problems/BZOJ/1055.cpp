/*
[HAOI2008]玩具取名
分析：can[i][j][k]表示[i..j]能否变成字符k
	  转移：can[i][j][k]|={can[i][p][k.a]&&can[p+1][j][k.b]} 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200,INF=0x3f3f3f3f;
char p[4]={'W','I','N','G'};
int q[255],t[4],can[MAXN+3][MAXN+3][4];
char ch[MAXN+3],a[4][20][2];
bool dp(int l,int r,int k){
	if(l==r)return(ch[l]==p[k]);
	int &res=can[l][r][k];
	if(res!=-1)return res;
	for(int i=1;i<=t[k];i++)
		for(int j=l;j<=r-1;j++)
			if(dp(l,j,q[a[k][i][0]])&&dp(j+1,r,q[a[k][i][1]]))
				return res=true;
	return res=false;
}
int main(){
	memset(can,-1,sizeof(can));
	for(int i=0;i<4;i++)q[p[i]]=i;
	for(int i=0;i<4;i++)scanf("%d",&t[i]);
	for(int i=0;i<4;i++)
		for(int j=1;j<=t[i];j++)scanf("%s",a[i][j]);
	scanf("%s",ch+1);
	int n=strlen(ch+1);
	bool flag=0;
	for(int i=0;i<4;i++)
		if(dp(1,n,i))flag=1,putchar(p[i]);
	if(!flag)puts("The name is wrong!");
	return 0;
}
