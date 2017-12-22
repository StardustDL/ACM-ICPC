/*

*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=300,M=7*12;
int link[MAXN+3],n;
bool mp[MAXN+3][MAXN+3],vis[M+3];
bool find(int u){
	for(int i=1;i<=M;i++){//这里是m 
		if(mp[u][i] && !vis[i]){
			vis[i]=1;
			if(link[i]==-1 || find(link[i])){
				link[i]=u;
				return true;
			}
		}
	}
	return false;
}
int maxpart(){
	memset(link,-1,sizeof(link));
	int ans=0;
	for(int i=1;i<=n;i++){//注意这里是n 
		memset(vis,0,sizeof(vis));
		if(find(i))ans++;
	}
	return ans;
}
int main(){
	while(~scanf("%d",&n)){
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++){
			int cnt,a,b;scanf("%d",&cnt);
			while(cnt--){
				scanf("%d%d",&a,&b);
				mp[i][(a-1)*12+b]=1;
			}
		}
		printf("%d\n",maxpart());
	}
	return 0;
}

