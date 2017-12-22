/*
[Usaco2007 Dec]队列变换 
分析：贪心，注意这种情况：AABA，左右端点相等，应该从左向右，和从右向左比，选较小的，这样最坏N^2，但是能水过
	  正解后缀数组预处理比较（翻转接后面） 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
char str[MAXN+3];
int n;
bool isleft(int l,int r){
	while(l<r){
		if(str[l]==str[r])l++,r--;
		else return str[l]<str[r];
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){getchar();str[i]=getchar();}
	for(int i=1,l=1,r=n;i<=n;i++){
		if(isleft(l,r))putchar(str[l++]);
		else putchar(str[r--]);
		if(i%80==0)puts("");
	}
	return 0;
}

