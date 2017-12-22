/*
NUMBER BASE CONVERSION
题意：将一个k进制的高精度数字A转换成m进制数B（k,m<=62）
分析：短除法，高精度 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=2000;
char STR[]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
char temp[MAXN+3];
int id[153],ans[MAXN+3],n,pos,T,m;
struct bign{
	int len,v[MAXN+3];
	bign(){init();}
	void init(){len=1;memset(v,0,sizeof(v));}
	void adjust(){
		while(!v[len-1]&&len>1)len--;
	}
	bign operator % (const int mod)const{
		bign t;
		t.len=len;
		int ys=0;
		for(int i=len-1;i>=0;i--){
			ys=ys*n+v[i];
			t.v[i]=ys/mod;
			ys%=mod;
		}
		ans[++pos]=ys;
		t.adjust();
		return t;
	}
	void output(){
		for(int i=len-1;i>=0;i--)putchar(STR[v[i]]);
	}
	void input(){
		init();
		scanf("%s",temp);
		len=strlen(temp);
		for(int i=len;i;i--){
			v[len-i]=id[temp[i-1]];
		}
	}
};
bool iszero(bign &t){
	return t.len==1&&t.v[0]==0;
}
bign big;
int main(){
	for(int i=0;STR[i]!='\0';i++)id[STR[i]]=i;
	for(scanf("%d",&T);T;T--){
		scanf("%d%d",&n,&m);
		pos=0;big.input();
		printf("%d %s\n%d ",n,temp,m);
		while(!iszero(big))big=big%m;
		if(pos)while(pos)putchar(STR[ans[pos--]]);
		else putchar('0');
		puts("\n");
	}
	return 0;
}

