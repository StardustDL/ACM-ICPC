/*
[Poi2008]海报PLA
分析：单调栈 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=250000,INF=0x3f3f3f3f;
int n,st[MAXN+3],tp=0,ans=0; 
int main(){
	scanf("%d",&n);
	for(int i=1,x,p;i<=n;i++){
		scanf("%d%d",&p,&x);
		while(tp&&x<=st[tp]){
			if(x<st[tp])ans++;
			tp--;
		}
		st[++tp]=x;
	}
	printf("%d\n",ans+tp);
	return 0;
}

