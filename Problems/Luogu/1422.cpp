/*
小玉家的电费
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int main(){
	double ans=0;int n;
	scanf("%d",&n);
	if(n>400){
		ans+=(n-400)*0.5663;
		n=400;
	}
	if(n>150){
		ans+=(n-150)*0.4663;
		n=150;
	}
	ans+=n*0.4463;
	printf("%.1f",ans);
	return 0;
}

