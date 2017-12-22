/*
Holding Bin-Laden Captive!
题意：给出价值为2,3,5的硬币枚数，求用这些硬币不能组成的最小金额
分析：网上题解给的母函数，但其实大可不必
	  先判断能否用1,2组成[1..4]的金额，若能那么对于[1..c*5+a+b*2]的金额均能组成 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int a,b,c;
int main(){
	while(scanf("%d%d%d",&a,&b,&c),a+b+c>0){
		if(/*a>=4||a>=1&&b>=2||a>=2&&b>=1||a>=3&&b>=1*/a&&(a+b*2>=4))printf("%d\n",c*5+a+b*2+1);
		else printf("%d\n",(a==0?1:b*2+1+a));
	}
	return 0;
}

