/*
Sum of Consecutive Prime Numbers
题意：求一个数可以表示成多少种连续素数的和。
分析：先预处理素数，然后枚举左右端点 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
bitset<MAXN+3> isp=0;
int ps[MAXN+3],s[MAXN+3],cnt=0,n,ans=0;
int main(){
	for(int i=2;i<=MAXN;i++){
		if(isp[i])continue;
		ps[++cnt]=i;s[cnt]=s[cnt-1]+i;
		for(int j=i*i;j<=MAXN;j+=i)isp[j]=1;
	}
	while(scanf("%d",&n),n){
		ans=0;
		for(int l=1;l<=cnt;l++){
			for(int r=l;r<=cnt;r++){
				if(s[r]-s[l-1]>n)break;//若大于就退出 
				if(s[r]-s[l-1]==n)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

