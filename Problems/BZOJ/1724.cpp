/*
[Usaco2006 Nov]Fence Repair 切割木板
分析：倒着的合并果子，注意不要认为从大到小切就行。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue> 
using namespace std;
const int MAXN=20000,INF=0x3f3f3f3f;
int n,a[MAXN+3];
priority_queue<int,vector<int>,greater<int> > q;
long long ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){scanf("%d",&x);q.push(x);}
	for(;n>1;n--){
		int x=q.top();q.pop();
		int y=q.top();q.pop();
		ans+=(x+y);q.push(x+y);
	}
	printf("%lld\n",ans);
	return 0;
}

