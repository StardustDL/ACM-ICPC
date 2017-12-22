/*
Paths on a Grid
分析：标准C(n+m,m)，一个小优化：C(n+m,min(n,m))
	  但是暴力会超时，采用拆分阶乘，逐项相除，再乘以前面所有项之积。这种方法用一个循环就OK了，时间复杂度只有O(n-m)，非常可观。
	  详细见代码，C(5,2)=5!/(2!3!)=5/3*4/2*3/1
	  注意精度问题 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef unsigned int UI;
UI C(UI n,UI m){
	double ans=1.0;
	while(m>0)ans*=(double)(n--)/(double)(m--);
	return (UI)(ans+0.5);//强制转换会舍去，先加0.5，实现4舍5入 
}
int main(){
	UI n,m;
	while(scanf("%u%u",&n,&m)&&(n!=0||m!=0))//n,m可能有一个为0 
		printf("%u\n",C(n+m,min(n,m)));
	return 0;
}

