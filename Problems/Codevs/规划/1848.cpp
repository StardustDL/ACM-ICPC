/*
迎春舞会之集体舞
分析：类似棋盘DP，f[i][j]表示到(i,j)点的最大三角形深度
	  这道题不用考虑另一种三角形 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100*2;
typedef int arr[MAXN+3][MAXN+3];
int n;
arr a,f;
void init(){
	scanf("%d\n",&n);
	char c;int i=1,j=1;
	while(scanf("%c",&c)==1){
		switch(c){
			case ' ':break;
			case '\n':i++;j=1;break;
			case '#':a[i][j]=0;j++;break;
			case '-':a[i][j]=1;j++;break;
		}
	}
}
int work(){
	int t=2*n-1,m=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=t-i;j+=2){
			if(!a[i][j])continue;
			if(a[i-1][j+1])f[i][j]=min(f[i-1][j],f[i-1][j+2])+1;
			else f[i][j]=1;
			m=max(m,f[i][j]);
		}
	}
	return m*m;//注意返回m*m，这个结果可以推一下
}
int main(){
	init();
	cout<<work(); 
}
