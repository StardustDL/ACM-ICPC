/*
编辑距离问题
分析：此题不太好想DP，但是可能会想到最长公共子序列，
	  此题的转移方程和LCS就很像，
	  opt[i][j]表示A[0..i-1]转换成B[0..j-1]的最优解
	  则有opt[i][j]=	尾字符不等时（相等时opt[i][j]=opt[i-1][j-1] 
	  	min{opt[i-1][j]		A末尾删除一个字符 
	  		,opt[i][j-1]	A末尾增加一个字符 
			,opt[i-1][j-1]} A末尾改变一个字符
	   还有就是初始化了
		opt[i=1..strlen(A)][0]=i;
		opt[0][i=1..strlen(B)]=i;
		意义是A串转空串为A串长度，空串转B串为B串长度 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=4000;
int opt[MAXN+3][MAXN+3],n;
char sa[MAXN+3],sb[MAXN+3];
int dp(){
	int la=strlen(sa),lb=strlen(sb);
	for(int i=1;i<=la;i++)opt[i][0]=i;
	for(int i=1;i<=lb;i++)opt[0][i]=i;
	for(int i=1;i<=la;i++){
		for(int j=1;j<=lb;j++){
			if(sa[i-1]==sb[j-1])opt[i][j]=opt[i-1][j-1];
			else opt[i][j]=min(min(opt[i-1][j],opt[i][j-1]),opt[i-1][j-1])+1;
		}
	}
	return opt[la][lb];
}
int main(){
	cin>>sa>>sb;
	cout<<dp();
	return 0;
}
