/*
美元=doller=刀=knife
分析：本来想DP，但题解上贪心就过了，很无语
	  贪心的思路是：比较相邻的两天，如果(前一天/今天)>1，那么就兑换（实际上相当于兑换了两次）
	  正确性怎么证明呢？ 
*/
#include<iostream>
#include<cstdio>
using namespace std;
int a,b,n;
double ans=100.0;
int main(){
	cin>>n>>a;
	n--;
	while(n-->0){
		cin>>b;
		if(a>b)ans*=a*1.0/b;
		a=b;
	}
	printf("%.2lf",ans);
	return 0;
}
