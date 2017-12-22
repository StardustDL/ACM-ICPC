/*
Muddy Fields
题意：一个由r行c列方格组成的田地，里面有若干个方格充满泥泞，其余方格都是草。要用长度不限，宽度为1的长木板来覆盖这些泥方格，但不能覆盖草地。最少要用多少个长木板？
分析：【经典】由于不能覆盖草地，这道题显得相当难。看别人的题解看了很久才明白它是如何跟二分匹配联系在一起的。这个建图实在是精妙。我们先把同一行每一段连续的泥方格作为一个顶点（其实就是一个长木板），这些顶点放进去集合x；而同一列每一段连续的泥方格也作为一个顶点，放进集合y。a∈x,b∈y，a,b若有相交则建一条边（a,b）。巧妙之处就在这条边，每条边所表示的就是原来的图中的一个泥方格，边与泥方格存在一一对应关系。若选了a(a∈x或a∈y)木板，则所有与a关联的边所表示的泥方格都会被覆盖。所以现在的问题就变成，求这个二分图的最小点覆盖数。由公式：最小点覆盖数＝最大匹配数，即可知只要求最大匹配就OK。
	  另外，这道题坑爹之处是，图的大小不止50*50
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<bitset>
using namespace std;
const int MAXN=500,INF=0x3f3f3f3f;
bool mp[MAXN+3][MAXN+3];
int M[MAXN+3][MAXN+3];
int r,c,link[MAXN+3];
bitset<MAXN+3> vis;
vector<int> g[MAXN+3];
bool find(int u){
	for(int i=0;i<g[u].size();i++){
		if(!vis[g[u][i]]){
			vis[g[u][i]]=1;
			if(!link[g[u][i]]||find(link[g[u][i]])){
				link[g[u][i]]=u;return true;
			}
		}
	}
	return false;
}
int maxpart(int n){
	memset(link,0,sizeof(link));int ans=0;
	for(int i=1;i<=n;i++)vis=0,ans+=find(i);
	return ans;
}
void input(){
	char t;
	scanf("%d%d",&r,&c);
	getchar();
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			t=getchar();
			if(t=='*')mp[i][j]=1;
			else mp[i][j]=0;
		}
		getchar();
	}
	
}
int build(){
	int nx=0,ny=0;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(mp[i][j]){
				nx++;
				while(j<=c&&mp[i][j])M[i][j++]=nx;
			}
		}
	}
	for(int j=1;j<=c;j++){
		for(int i=1;i<=r;i++){
			if(mp[i][j]){
				ny++;
				while(i<=r&&mp[i][j])g[M[i++][j]].push_back(ny);
			}
		}
	}
	return nx;
}
int main(){
	input();
	printf("%d\n",maxpart(build()));
	return 0;
}

