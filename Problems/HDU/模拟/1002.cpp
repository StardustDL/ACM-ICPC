/*
A + B Problem II
分析：高精加，memset的参数是传进函数的指针时，memset无效 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int a[MAXN+3],cnta=0,b[MAXN+3],cntb=0,c[MAXN+3],cntc=0,temp[MAXN+3];
void aplusb(int *a,int *b,int cnta,int cntb,int *c,int &cntc){
	cntc=max(cnta,cntb);
	for(int i=1;i<=cntc;i++){
		c[i]+=a[i]+b[i];
		if(c[i]>=10){
			c[i+1]+=c[i]/10;
			c[i]%=10;
		}
	}
	if(c[cntc+1]>0)cntc++;
}
void input(int* A,int &cnt){
	memset(temp,0,sizeof(A)); 
	cnt=0;
	char c;
	while(scanf("%c",&c),c!=' '&&c!='\n'){
		temp[++cnt]=c-'0';
	}
	for(int i=1;i<=cnt;i++){
		A[cnt-i+1]=temp[i];
	}
}
void output(int* A,int cnt){
	for(int i=cnt;i>=1;i--){
		printf("%d",A[i]);
	}
}
int main(){
	int T;
	scanf("%d\n",&T);
	for(int i=1;i<=T;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		input(a,cnta);
		input(b,cntb);
		aplusb(a,b,cnta,cntb,c,cntc);
		//output(temp,cntc);
		printf("Case %d:\n",i);
		output(a,cnta);
		printf(" + ");
		output(b,cntb);
		printf(" = ");
		output(c,cntc);
		puts("");
		if(i<T)puts("");
	}
	return 0;
}

