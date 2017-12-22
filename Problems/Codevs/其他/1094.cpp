/*
FBI树
分析：直接模拟，不要管n，直接strlen 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int n;
char str[2*MAXN+3];
int build(int l,int r){
	if(l==r){
		putchar((str[l]=='1')?'I':'B');
		return str[l]=='1';//B,I
	}
	int a=build(l,(l+r)>>1),b=build(((l+r)>>1)+1,r),ans;
	if(a^b || a==2){
		putchar('F');
		return 2;
	}
	else{
		putchar(a==1?'I':'B');
		return a;
	}
}
int main(){
	cin>>n>>(str+1);
	build(1,strlen(str+1));
	return 0;
}

