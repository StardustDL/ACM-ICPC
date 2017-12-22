/*
[HEOI2012]朋友圈
分析：题意就是给了张图，求最大团。然而一般图的最大团是NP。最大团=反图的最大点独立集 
	  不过，仔细看题，可以发现，构造反图后，A国变成了两个团——奇偶
	  B国奇偶之间构成二分图，二分图由第二个条件可以得到 
	  于是A图中可能贡献0,1,2个点，其代价是B中一些点失效。
	  那么枚举A的所有情况，在B中去掉不能选的点，跑二分图最大匹配，得到最大匹配，而最大独立集=总点数-最大匹配=B-不能选的点数-最大匹配
	  奇迹般的跑的很快0.0，496 MS 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector> 
using namespace std;
const int MAXN=3000,INF=0x3f3f3f3f;
bool mp[MAXN+3][MAXN+3];
int match[MAXN+3];
bool vis[MAXN+3],can[MAXN+3];
vector<int> g[MAXN+3];
int A,B,m;
int a[MAXN+3],b[MAXN+3];
int count_one(int x){//用类似lowbit的方法统计1的个数 
	int ans=0;
	while(x)x-=(x&-x),ans++;
	return ans;
}
bool hungry(int x){
	if(can[x]==0)return false;//如果这个点去掉，就不选 
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int t=g[x][i];
		if(!can[t] || vis[t])continue;
		if(match[t]==0 || hungry(match[t])){
			match[x]=t;
			return true; 
		} 
	}
	return false;
}
int get_max_point(int x=0,int y=0){
	int ans=B;memset(can,1,sizeof(can));
	for(int i=1;i<=B;i++)//处理需要去掉的点 
		if(mp[x][i] || mp[y][i])ans--,can[i]=0;
	memset(match,0,sizeof(match));
	for(int i=1;i<=B;i++){//跑匹配，注意根据建边，从奇数到偶数 
		if(b[i]&1){
			memset(vis,0,sizeof(vis));
			if(hungry(i))ans--;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&A,&B,&m);
	for(int i=1;i<=A;i++)scanf("%d",&a[i]);
	for(int i=1;i<=B;i++)scanf("%d",&b[i]);
	memset(mp,1,sizeof(mp));
	for(int x,y,i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		mp[x][y]=0;//注意是反图 
	}
	for(int i=1;i<=B;i++){//由奇数到偶数建边 
		if(b[i]&1){
			for(int j=1;j<=B;j++){
				if(!(b[j]&1)){
					if(!(count_one(b[i]|b[j])&1))g[i].push_back(j);
				}
			}
		}
	}
	for(int i=1;i<=B;i++)mp[0][i]=0;
	int ans=get_max_point();//不选A 
	for(int i=1;i<=A;i++)ans=max(ans,get_max_point(i)+1);//A中选一个 
	for(int i=1;i<=A;i++){
		if(a[i]&1){
			for(int j=1;j<=A;j++)
				if(!(a[j]&1))ans=max(ans,get_max_point(i,j)+2);//A中选两个（注意奇偶要不同） 
		}
	}
	printf("%d\n",ans);
	return 0;
}

