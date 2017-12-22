/*
Prison rearrangement
���⣺M���ﷸ���������������У����ھ����������ǵ����ڵļ��������м����˲�����ͬһ�������У�����󽻻����ٶ���
������ע����ڸ���һЩ�ԣ�ʵ���Ͽ������ɭ�֣����������ͱ���������˵Ľ�����������ʵ�����һ����ά��������
	  ����ʵ�֣�����Ⱦɫ��Ҳ����������Ĵ���һ����㣬��¼ÿ����ͨ���е���������
	  ע��Ƚϴ��������ͼ�������������𣬺� Team them up������ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200;
vector<int> g[MAXN*2+3];
bitset<MAXN*2+3> vis;
bitset<MAXN+3> opt[MAXN+3];
int cnt[2],mark[MAXN*2+3],m,wx[MAXN*2+3],wy[MAXN*2+3],wn;
void dfs(int u){
	cnt[mark[u]]++;
	for(int i=0;i<g[u].size();i++){
		if(!vis[g[u][i]]){
			vis[g[u][i]]=1;
			dfs(g[u][i]);
		}
	}
}
void input(){
	int r,x,y;
	scanf("%d%d",&m,&r);
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=m<<1;i++)g[i].clear();
	for(int i=1;i<=m;i++){
		mark[i]=0;mark[i+m]=1;
	}
	while(r--){
		scanf("%d%d",&x,&y);
		g[x].push_back(y+m);
		g[y+m].push_back(x);
	}
	wn=0;
	vis=0;
	for(int i=1;i<=m<<1;i++){
		if(vis[i])continue;
		cnt[0]=cnt[1]=0;
		vis[i]=1;
		dfs(i);
		if(cnt[0]>0||cnt[1]>0){
			wx[++wn]=cnt[0];
			wy[wn]=cnt[1];
		}
	}
	/*for(int i=1;i<=wn;i++){
		cout<<wx[i]<<" "<<wy[i]<<endl;
	}*/
}
int dp(){
	int n=m>>1;
	for(int i=0;i<=n;i++)opt[i]=0;
	opt[0][0]=1;
	for(int i=1;i<=wn;i++){
		for(int j=n;j>=wx[i];j--){
			for(int k=n;k>=wy[i];k--){
				opt[j][k]=opt[j][k]||opt[j-wx[i]][k-wy[i]];
			}
		}
	}
	while(!opt[n][n])n--;
	return n;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		input();
		printf("%d\n",dp());
	}
	return 0;
}


