/*
[Beijing wc2012]算不出的算式
分析：可转化为方程为y=(q/p)x的直线在左边和下面的点的个数，注意求和上指标是x,y的范围，各是一半，
		所以答案是总点数的四分之一 
		注意p==q和p!=q时分别是(p-1)*(p+1)/4和(p-1)*(q-1)/4 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
LL p,q; 
int main(){
	scanf("%lld%lld",&p,&q);
	printf("%lld",(p==q)?(p-1)*(q+1)/4:(p-1)*(q-1)/4);
	return 0;
}




