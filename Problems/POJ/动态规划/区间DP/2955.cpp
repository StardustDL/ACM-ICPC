/*
Brackets
题意：给你一串()[]括号，要你求出这串括号的最大匹配个数，如'('与')'匹配，为2个，'['与']'匹配，为2个，其他不能匹配
分析：区间DP，转移方程是[i..j]的最优解=i能和k匹配 ? [i+1..k-1]+2+[k+1,j]:[i..j]，注意要所有k全部扫一遍 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
char str[MAXN+3]; 
int opt[MAXN+3][MAXN+3],n;
int main(){
	while(scanf("%s",str+1),str[1]!='e'){
		n=strlen(str+1);
		memset(opt,0,sizeof(opt));
		for(int i=n-1;i>=1;i--){
			for(int j=i+1;j<=n;j++){
				int &t=opt[i][j];
				t=opt[i+1][j];
				for(int k=i+1;k<=j;k++){
					if(str[i]=='('&&str[k]==')' || str[i]=='['&&str[k]==']')t=max(t,opt[i+1][k-1]+2+opt[k+1][j]);
				}
			}
		}
		printf("%d\n",opt[1][n]);
	}
	return 0;
}

