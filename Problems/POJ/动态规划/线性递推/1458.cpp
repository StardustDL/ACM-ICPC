/*
Common Subsequence
分析：最长公共子序列，题目没给范围，坑
	  opt[i][j]=opt[i-1][j-1]+1 |a[i]==b[j]
	  			max{opt[i-1][j],opt[i][j-1]} |a[i]!=b[i]
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000;
int opt[MAXN+3][MAXN+3];
char a[MAXN+3],b[MAXN+3];
int get(int x,int y){
	if(x==-1||y==-1)return 0;
	else return opt[x][y];
}
int dp(){
	memset(opt,0,sizeof(opt));
	int la=strlen(a),lb=strlen(b),ln=max(la,lb);
	for(int i=0;i<la;i++){
		for(int j=0;j<lb;j++){
			if(a[i]==b[j])opt[i][j]=get(i-1,j-1)+1;
			else opt[i][j]=max(get(i-1,j),get(i,j-1));
		}
	}
	return opt[la-1][lb-1];
}
int main(){
	while(cin>>a>>b)cout<<dp()<<endl; 
	return 0;
}
