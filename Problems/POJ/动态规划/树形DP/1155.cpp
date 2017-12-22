/*
TELE
���⣺��һ������̨Ҫ�õ�������ת����Ŀ�����ֵ���������һ�������Ľڵ�Ϊ��תվ�����û������ڵ�ı��Ϊ1~N,����1Ϊ��վ��2~(N-M)Ϊ��תվ������վ����תվͳ��Ϊת��վ��N-M+1~NΪ�û������ӽ�Ŀ��һ���ط�������һ���ط���Ҫ���ã�ͬʱÿһ���û�Ը�����Ӧ��Ǯ�������ӽ�Ŀ�����ڵ������ǣ��ڵ���̨��������ǰ���£�Ҫ������������ж��ٸ��û����Կ������ӽ�Ŀ��
˼·�������Ͻ��б�����������uΪ��������,������������j���û�����������Ǯ����ÿ��������ά����ǰ������С����ʵ���Ż���Ȼ��ö�ٹ���j���û�������k���ڴ�������
	  ���̣�opt[u][j]=max(opt[u][j],opt[u][j-k]-w(e)+val[v]+opt[v][k]
	  ע������Ϊ�û������ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=3000;
struct edge{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge> es;
vector<int> g[MAXN+3];
int n,m,val[MAXN+3],opt[MAXN+3][MAXN+3];
void addedge(int u,int v,int w){
	es.push_back(edge(u,v,w));
	es.push_back(edge(v,u,w));
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
int dp(int u,int fa){
	//if(g[u].size()==0){/*opt[u][1]=val[u];*/return 1;}
	int ans=0,p,now;
	for(int i=0;i<g[u].size();i++){
		edge &e=es[g[u][i]];
		if(e.v==fa)continue;
		now=dp(e.v,u);  
        if(e.v>=n-m+1)++now,p=1;//���û� 
        else p=0;
        ans+=now;
        for(int j=min(m,ans);j>=1;j--){//����ע��һ��Ҫj=min(m,ans),���Ӷ�ΪO(n^3)=>�ӽ�O(n^2)  
            for(int k=min(j,now);k>=1;k--){//��uΪ��������������j���û�������k���û�����vΪ��������ʱ���������Ǯ  
                opt[u][j]=max(opt[u][j],opt[u][j-k]+opt[e.v][k-p]-e.w+val[e.v]);  
            }
        }
	}
	return ans;
}
void input(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)opt[i][j]=-INF;
	int k,v,c;
	for(int i=1;i<=n-m;i++){
		scanf("%d",&k);
		val[i]=0;
		while(k--){
			scanf("%d%d",&v,&c);
			addedge(i,v,c);
		}
	}
	for(int i=n-m+1;i<=n;i++)scanf("%d",&val[i]);
}
int main(){
	input();
	dp(1,-1);
	int ans=0;
	for(int i=m;i>0;i--){
		if(opt[1][i]>=0){
			printf("%d\n",i);
			break;
		}
	}
	return 0;
}

