/*
[HNOI2006]超级英雄Hero
分析：直接二分图匹配，听说并查集能做？ 
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1000; 
int mp[MAXN+3][MAXN+3],match[MAXN+3];
int n,m;
bool vis[MAXN+3];
bool find(int x){
	for(int i=0;i<n;i++){	   
		if(!vis[i]&&mp[x][i]){
			vis[i]=1;
			if(!match[i]||find(match[i])){
				match[i]=x;return 1;
			}
		}
	}
    return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++){
		scanf("%d%d",&x,&y);
		mp[i][x]=mp[i][y]=1;
	}
    int ans=0;
    for(int i=1;i<=m;i++){
    	memset(vis,0,sizeof(vis));
    	if(find(i))ans++;
    	else break;
    }
   	printf("%d\n",ans);
	return 0;
}
