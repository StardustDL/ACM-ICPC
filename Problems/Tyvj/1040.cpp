/*
表达式计算
分析：要用高精度
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
typedef long long LL;
char c;
LL ans=0,t=0;
int main(){
	while(~scanf("%c",&c)){
		if(c=='+'){
			ans+=t;t=0;
		}
		else if(c>='0'&&c<='9'){
			t=t*10LL+c-'0';
		}
	}
	cout<<(ans+=t)<<endl;
	return 0;
}

