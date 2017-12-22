/*
Muddy Fields
���⣺һ����r��c�з�����ɵ���أ����������ɸ����������Ţ�����෽���ǲݡ�Ҫ�ó��Ȳ��ޣ����Ϊ1�ĳ�ľ����������Щ�෽�񣬵����ܸ��ǲݵء�����Ҫ�ö��ٸ���ľ�壿
�����������䡿���ڲ��ܸ��ǲݵأ�������Ե��൱�ѡ������˵���⿴�˺ܾò�����������θ�����ƥ����ϵ��һ��ġ������ͼʵ���Ǿ�������Ȱ�ͬһ��ÿһ���������෽����Ϊһ�����㣨��ʵ����һ����ľ�壩����Щ����Ž�ȥ����x����ͬһ��ÿһ���������෽��Ҳ��Ϊһ�����㣬�Ž�����y��a��x,b��y��a,b�����ཻ��һ���ߣ�a,b��������֮�����������ߣ�ÿ��������ʾ�ľ���ԭ����ͼ�е�һ���෽�񣬱����෽�����һһ��Ӧ��ϵ����ѡ��a(a��x��a��y)ľ�壬��������a�����ı�����ʾ���෽�񶼻ᱻ���ǡ��������ڵ�����ͱ�ɣ����������ͼ����С�㸲�������ɹ�ʽ����С�㸲���������ƥ����������ֻ֪Ҫ�����ƥ���OK��
	  ���⣬�����ӵ�֮���ǣ�ͼ�Ĵ�С��ֹ50*50
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

