/*
[ZJOI2007]������Ϸ
������ͬ��ͬ�еĵ����۾������ٴα任��Ȼͬ�л�ͬ�У�������Ŀ��ת��Ϊ�ܲ����ҵ�n�����಻ͬ�л�ͬ�еĵ㡣��˵��ÿ���ҵ�һ�����ϵĵ�
	  ����ͼƥ�� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200,INF=0x3f3f3f3f;
int mp[MAXN+3][MAXN+3],match[MAXN+3],vis[MAXN+3],n;
bool augment(int u){
	for(int i=1;i<=n;i++){
		if(vis[i] || mp[u][i]==0)continue;
		vis[i]=1;//ע���������������vis[u]=1����������ĵ� 
		if(match[i]==0 || augment(match[i])){match[i]=u;return true;}
	}
	return false;
}
bool solve(){
	memset(match,0,sizeof(match));
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(!augment(i))return false;
	}
	return true;
}
int main(){
	int t;scanf("%d",&t);
	for(;t;t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&mp[i][j]);
		printf("%s\n",solve()?"Yes":"No");
	}
	return 0;
}

