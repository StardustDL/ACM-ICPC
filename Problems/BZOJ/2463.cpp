/*
[中山市选2009]谁能赢呢？
分析：n*n是偶数时先手必胜，否则后手必胜 
*/
#include<cstdio>
int main(){
	int n;
	while(scanf("%d",&n),n)printf("%s\n",((n&1)?"Bob":"Alice"));
	return 0;
}

