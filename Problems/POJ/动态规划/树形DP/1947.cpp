/*
Rebuilding Roads
���⣺����n,p��һ����n���ڵ㣬Ҫ�����ټ�ȥ���ٵı��Ƕ��٣�ʣ��p���ڵ�
������dp[s][i]:��¼s��㣬Ҫ�õ�һ��j���ڵ������ȥ�������ٱ���
	  ���������k��
	  	1)�����ȥ��k��������dp[s][i]=min(dp[s][j]+dp[k][i-j])  0<=j<=i
		2)���ȥ��k��������dp[s][i]=dp[s][i]+1
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=150;
vector<int> g[MAXN+3];
int n,p,opt[MAXN+3][MAXN+3];
void addedge(int u,int v){
	g[u].push_back(v);
	g[v].push_back(u);
}
void input(){
	scanf("%d%d",&n,&p);
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		addedge(x,y);
	}
}
void dp(int u,int pa){
	memset(opt[u],INF,sizeof(opt[u]));
	opt[u][1]=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==pa)continue;
		dp(v,u);
		for(int j=p;j>=1;j--){
			int tmp=opt[u][j]+1;
			for(int k=1;k<j;k++){
				tmp=min(tmp,opt[u][k]+opt[v][j-k]);
			}
			opt[u][j]=tmp;
		}
	}
}
int solve(int root){//����Ҫ�������е㣨ÿ���㶼���ܳ�Ϊ���� 
	dp(root,-1);
	int ans=opt[root][p];
	for(int i=1;i<=n;i++){
		ans=min(ans,opt[i][p]+1);//�����ڵ��⣬������������Ϊ���������Ⱥ͸��׶ϱ� 
	}
	return ans;
}
int main(){
	input();
	printf("%d",solve(1));
	return 0;
}

