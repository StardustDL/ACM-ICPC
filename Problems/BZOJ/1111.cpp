/*
[POI2007]�Ľ��Ƶ���ƽWag
���������Ƚ�nת��Ϊ�Ľ��ƣ��ӵ�λ����λ����DP
		f[i]��ʾ��һλ������һλ��λ
		g[i]��ʾ��һλ����һλ��λ��������Ǹ�������i
		f[0]=0,g[0]=inf
		f[i]=merge(f[i-1]+b[i],g[i-1]+b[i]+1)
		g[i]=merge(f[i-1]+4-b[i],g[i-1]+3-b[i]) 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f,MOD=1000000000;
struct D{
	int v,c;
	D(){}
	D(int v,int c):v(v),c(c){}
	D operator +(const int x)const{
		return D(v+x,c);
	}
}f[MAXN+3],g[MAXN+3];
D update(D a,D b){
	return a.v==b.v?D(a.v,(a.c+b.c)%MOD):((a.v<b.v)?a:b);
}
int a[MAXN+3],b[MAXN+3],n,l,i;
char s[MAXN+3];
int main(){
	for(scanf("%s",s),l=strlen(s),i=1;i<=l;i++)a[i]=s[l-i]-'0';
	while(l){//ת��4����  
		for(i=l,a[0]=0;i;i--)a[i-1]+=(a[i]&3)*10,a[i]>>=2;
		for(b[++n]=a[0]/10;l&&!a[l];l--);
	}
	for(f[0]=D(0,1),g[0]=D(MAXN,0),n++,i=1;i<=n;i++)
		f[i]=update(f[i-1]+b[i],g[i-1]+(b[i]+1)),g[i]=update(f[i-1]+(4-b[i]),g[i-1]+(3-b[i]));
	printf("%d\n",f[n].c);
	return 0;
}

