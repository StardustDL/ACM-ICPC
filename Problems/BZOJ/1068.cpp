/*
[SCOI2007]压缩
分析：令f[i][j][0..1]表示[i..j]压缩，使用/不适用M的最优解
	  三种压缩方式：
	  	只压缩前k个 
		在第k个位置分成两部分，分别压缩，中间加个M
		如果[i..j]是一个串的两倍，那么将前面的一半不使用M来压缩 ，后面一半替换成R 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50,INF=0x3f3f3f3f;
char str[MAXN+3];
int opt[MAXN+3][MAXN+3][2]; 
bool issame(int l,int r){
	int len=r-l+1;
	if(len&1)return false;
	len>>=1;
	for(int i=0;i<len;i++)if(str[l+i]!=str[l+len+i])return false;
	return true;
}
int dp(int l,int r,bool has){
	if(l==r)return 1;
	if(opt[l][r][has])return opt[l][r][has];
	int ans=r-l+1;
	for(int i=l;i<r;i++)ans=min(ans,dp(l,i,has)+r-i);
	if(has)for(int i=l;i<r;i++)ans=min(ans,dp(l,i,1)+1+dp(i+1,r,1));
	if(issame(l,r))ans=min(ans,dp(l,(l+r)>>1,0)+1);
	return opt[l][r][has]=ans;
}
int main(){
	scanf("%s",str);
	printf("%d\n",dp(0,strlen(str)-1,1));//has=1包含了has=0 
	return 0;
}

