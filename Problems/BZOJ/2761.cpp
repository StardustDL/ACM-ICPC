/*
[JLOI2011]不重复数字
分析：直接用set，注意bzoj不会过滤行末空格 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<set> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
set<int> S;
int main(){
	int T,n,x;
	scanf("%d",&T);
	while(T--){
		S.clear();
		scanf("%d",&n); 
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
			if(S.count(x))continue;
			S.insert(x);
			if(i==1)printf("%d",x);
			else printf(" %d",x);
		}
		puts("");
	}
	return 0;
}

