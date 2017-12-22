/*
[Usaco2008 Open]Roads Around The Farm分岔路口
分析：直接模拟，注意n<k+2时不能再分 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,k; 
int f(int x){
	if(x<k+2)return 1;
	if((x-k)&1)return 1;
	else return f((x-k)>>1)+f(x-((x-k)>>1));
}
int main(){
	scanf("%d%d",&n,&k);
	printf("%d\n",f(n));
	return 0;
}

