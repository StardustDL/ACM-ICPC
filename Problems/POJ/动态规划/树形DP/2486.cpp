/*
Apple Tree
���⣺����Ȩ��һ��������1�ڵ���K���������Ȩֵ
������ע����Իص���㣬���Զ���״̬��
	  ״̬dp[i][k][0]��ʾ��k�������ߵ�����£�Ů���ǻص�i�ڵ�Ե������ƻ������dp[i][k][1]��ʾ��k�������ߵ�����£�Ů���ǲ�һ���ص�i��������i��������ֹͣ���Ե������ƻ������
	  ״̬ת�Ʒ��̴������дΪ�����������Ǳ����� 
	  (1)dp[i][k][0]=Max{dp[i][k][0],{dp[i][k-l-2][0]+dp[j][l][0]|(i,j)}};
	  (2)dp[i][k][1]=Max{dp[i][k][1],{dp[i][k-l-2][0]+dp[j][l][1]|(i,j)}};
	  (3)dp[i][k][1]=Max{dp[i][k][1],{dp[i][k-l-2][1]+dp[j][l][0]|(i,j)}};
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100,MAXK=200;
int opt[MAXN+3][MAXK+3][2],n,k,val[MAXN+3];
//bitset<MAXN+3> vis;
vector<int> g[MAXN+3];
void dp(int u,int pa){
	//cout<<u<<endl;
	//vis[u]=1;
	for(int i=0;i<=k;i++)opt[u][i][0]=opt[u][i][1]=val[u]; 
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==pa)continue;dp(v,u);//�����ȡ���֣���ȡbitset����WA 
		//if(!vis[v])dp(v,u);
		for(int j=k;j>=0;j--){
			for(int p=0;p<=j;p++){
				opt[u][j+2][0]=max(opt[u][j+2][0],opt[u][j-p][0]+opt[v][p][0]);
				opt[u][j+1][1]=max(opt[u][j+1][1],opt[u][j-p][0]+opt[v][p][1]);
				opt[u][j+2][1]=max(opt[u][j+2][1],opt[u][j-p][1]+opt[v][p][0]);
			}
		}
	}
}
bool input(){
	if(scanf("%d%d",&n,&k)!=2)return false;
	for(int i=1;i<=n;i++){
		scanf("%d",&val[i]);
		g[i].clear();
	}
	int x,y;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	return true;
}
int main(){
	while(input()){
		memset(opt,0,sizeof(opt));
		dp(1,-1);
		//cout<<"!!!"<<endl;
		printf("%d\n",max(opt[1][k][0],opt[1][k][1]));
	}
	return 0;
}

