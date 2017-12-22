/*
[Noi2014]随机数生成器
分析：首先整个棋盘可以在nm的时间内求出，但是注意不要疯狂取模不然会T
		接着会发现一个比较逗比的性质，就是从1开始取到n*m，能取就取共取n+m-1个是最优的
		那么只要这样模拟一下即可
		注意2500万的数组只能开俩，要循环利用T T，（一个 是95M） 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
typedef long long LL; 
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,nm,q,top;
LL a,b,c,d;
int x[25000005],t[25000005],up[5005],down[5005],ans[10005];
void add(int a,int b){
	for(int i=1;i<=n;i++)
		if(i<a)up[i]=min(b,up[i]);
		else if(i>a)down[i]=max(b,down[i]);
}
int main(){
	memset(up,127/3,sizeof(up));
	x[0]=read();a=read();b=read();c=read();d=read();
	n=read();m=read();q=read();nm=n*m;
	for(int i=1;i<=nm;i++)
		x[i]=(x[i-1]*(a*x[i-1]+b)+c)%d,t[i]=i;
	for(int i=1;i<=nm;i++)
		swap(t[i],t[(x[i]%i)+1]);
	for(int i=1;i<=q;i++){
		int x=read(),y=read();
		swap(t[x],t[y]);
	}
	for(int i=1;i<=nm;i++)x[t[i]]=i;
	for(int i=1,a,b;i<=nm;i++){
		if(x[i]%m)a=x[i]/m+1;
		else a=x[i]/m;
		b=x[i]%m;if(!b)b+=m;
		if(b<=up[a]&&b>=down[a]){//保证没有用到(a,b)这个点 
			add(a,b);
			ans[++top]=i;
			if(top==n+m-1)break;
		}
	}
	for(int i=1;i<=top;i++){
		printf("%d",ans[i]);
		if(i!=top)printf(" ");
	}
	return 0;
}

