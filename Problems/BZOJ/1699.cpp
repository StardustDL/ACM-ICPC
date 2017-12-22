/*
[Usaco2007 Jan]Balanced Lineup排队
分析：RMQ问题，注意循环外层是j 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000,POW=18,INF=0x3f3f3f3f;
inline int read(){
    int x=0;bool sig=true;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')sig=false;
    for(;isdigit(ch);ch=getchar())x=10*x+ch-'0';return sig?x:-x;
}
inline void write(int x){
    if(x==0){putchar('0');return;}if(x<0)putchar('-'),x=-x;
    int len=0;static int buf[20];while(x)buf[len++]=x%10,x/=10;
    for(int i=len-1;i>=0;i--)putchar(buf[i]+'0');
}
int a[MAXN+3],mn[MAXN+3][POW+1],mx[MAXN+3][POW+1],n;
void init(){
	for(int i=1;i<=n;i++)mn[i][0]=mx[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
		}
	}
}
int solve(int l,int r){
	int k=0;while((1<<k+1)<r-l+1)k++;
	int ma=max(mx[l][k],mx[r-(1<<k)+1][k]),mb=min(mn[l][k],mn[r-(1<<k)+1][k]);
	return ma-mb;
}
int main(){
	n=read();int q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	init();
	for(int l,r;q;q--){
		l=read(),r=read();
		write(solve(l,r));
		puts("");
	}
	return 0;
}

