/*
Agri-Net
���⣺��n��ũ������֪��n��ũ����������ͨ����һ���ľ��룬����ÿ��ũ����Ҫװ���ˣ�����ô��װ�����ܽ�����ũ������ͨ����������Ҫʹ���˾�����С�������װ���˵��ܾ���
��������С�������������õ�Prim�����ý����� 
*/
#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f; 
bitset<MAXN+3> vis;
int d[MAXN+3],mp[MAXN+3][MAXN+3],n;
int prim(){
	int mi,v,ans=0;
	vis=0; 
	memcpy(d,mp[1],sizeof(d));
	for(int i=1;i<=n;i++){
		mi=INF;
		for(int j=1;j<=n;j++)
			if(!vis[j]&&d[j]<mi){
				mi=d[j];
				v=j;
			}
		vis[v]=1;
		for(int j=1;j<=n;j++)
			if(!vis[j])d[j]=min(d[j],mp[v][j]);
	}
	for(int i=1;i<=n;i++)ans+=d[i];
	return ans;
}
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&mp[i][j]);
		printf("%d\n",prim());
	}
	return 0;
}

