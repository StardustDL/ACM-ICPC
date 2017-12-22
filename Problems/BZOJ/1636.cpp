/*
[Usaco2007 Jan]Balanced Lineup
分析：RMQ+输入输出优化 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
int n,q,mn[MAXN+3][18],mx[MAXN+3][18],a[MAXN+3];
inline int getmax(int l,int r){
	int h=(r-l+1),k=0;
	while((1<<(k+1))<=h)k++;
	return max(mx[l][k],mx[r-(1<<k)+1][k]);
}
inline int getmin(int l,int r){
	int h=(r-l+1),k=0;
	while((1<<(k+1))<=h)k++;
	return min(mn[l][k],mn[r-(1<<k)+1][k]);
}
inline int read(){
	int x=0,f=1;char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return x*f;
}
char _outtmp[50];int _outlen;
inline void speak(int x,char tail){
	if(x==0)putchar('0');
	_outlen=0;
	while(x){_outtmp[++_outlen]=(char)('0'+(x%10));x/=10;}
	for(int i=_outlen;i;i--)putchar(_outtmp[i]);
	putchar(tail);
}
int main(){
	n=read();q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)mn[i][0]=mx[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
			mx[i][j]=max(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
		}
	}
	for(int a,b;q;q--){
		a=read(),b=read();
		speak(getmax(a,b)-getmin(a,b),'\n');
	}
	return 0;
}

