/*
Monster
分析：能砍死的三个充分条件：
	  1.OTK，2.第k回合砍死，3.休息之后血量比初始低，
	  注意开long long 和输出 
*/
#include<cstdio>
using namespace std;
const char ANS[2][5]={"NO","YES"};
long long h,a,b,k;int cnt=0;
int main(){
	while(scanf("%lld%lld%lld%lld",&h,&a,&b,&k),h+a+b+k)
		printf("Case #%d: %s\n",++cnt,ANS[(a>=h)||(a*k>=h+b*(k-1))||(a*k>b*(k+1))]);
	return 0;
}

