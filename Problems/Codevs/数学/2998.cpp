/*
鬼谷子的钱袋
分析：二进制拆分，可以先除2，注意不能有大于1的数多次出现 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
typedef long long LL;
LL m;
int ans;
int main(){
	scanf("%lld",&m);
	if(m==5){
		printf("3\n1 1 3");
		return 0;
	}
	ans=0;
	while((1LL<<ans)<m)ans++;
	printf("%d\n",ans);
	for(int i=0;i<ans-1;i++){
		if(i>0)putchar(' ');
		printf("%lld",1LL<<i);
		m-=(1LL<<i); 
	}
	if(m)printf(" %lld",m);
	return 0;
}

