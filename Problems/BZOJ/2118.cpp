/*
墨墨的等式
分析：同余系bfs，令mn为a[1]~a[n]中数的最小值。很显然，如果x能被凑出来，x+mn也能被凑出来。所以我们只需要知道对于每一个x属于[0,mn)，满足y%mn==x中最小的y，那么就能知道[1,R]中模mn等于x的数里能凑出来的个数。
		注意spfa的时候正无穷要大一点
		需要特殊处理一下a=0的情况，但是数据好像a!=0
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue> 
using namespace std;
typedef long long LL;
const int MAXN=500000;
queue<int> q;
LL d[MAXN+3],l,r;
int mn,n,a[MAXN+3];
bool inq[MAXN+3];
void spfa(int s){
	for(int i=1;i<mn;i++)d[i]=1LL<<62;
	d[0]=0;while(!q.empty())q.pop();
	q.push(s);inq[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for(int i=1;i<=n;i++){
			int v=(u+a[i])%mn;
			if(d[v]>d[u]+a[i]){
				d[v]=d[u]+a[i];
				if(!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
}
LL query(LL x){
	LL ans=0;
	for(int i=0;i<mn;i++)if(d[i]<=x)ans+=(x-d[i])/mn+1;
	return ans;
}
int main(){
	scanf("%d%lld%lld",&n,&l,&r);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);if(a[i]==0)i--,n--;}mn=*min_element(a+1,a+n+1);
	spfa(0);
	printf("%lld\n",query(r)-query(l-1));
	return 0;
}

