/*
[HNOI2015]�������
���⣺����һ�������޻�ͼ������Ҫ�����һ���ߣ���������1Ϊ��������ͼ����  
������http://blog.csdn.net/popoqqq/article/details/45194103
		���Ȳ����Ǽ���������ߣ���ô���ͼ��һ��DAG 
		�������㷨�����ۿ�֪����������ڵ���ÿ���㶼ѡ��һ����ߣ�����û�л������һ�����γ�һ������ͼ 
		��˴𰸾��ǡ�i=2..n degreei ����degreei��ʾ��i��������
		���ڼ���������֮��������Ȼ�������������ʽ�����������ͻ���һЩ���Ϸ��ķ�����ͳ�ƽ�����������Ҫ����Щ���Ϸ��ķ������� 
		һ������������Ϸ�����ôһ�����γ�һ����������һ�������¼���������� 
		������Ǽ����ķ�����ʵ�ǣ�  
		sigma{S��ԭͼ��t��s��һ��·���ĵ㼯 ,��i=2..n,i������S degreei}
		Ȼ��Ϳ���DP�� 
		f[i]= sigma{S��ԭͼ��t->i��һ��·���ĵ㼯 ,��i=2..n,i������S degreei}
		f[i]=sigma{f[j]|j->i}/degree[i]
		f[t]=( ��i=2..n degreei)/degree[t]
		ע��t=1ʱҪ����
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAXN=100000,MAXM=200000;
const LL MOD=1000000007;
struct edge{
	int v,nxt;
}es[MAXM+3];
int head[MAXN+3],tot,dg[MAXN+3],dg2[MAXN+3],n,m,s,t,q[MAXN+3];
LL inv[MAXM+3],ans,dp[MAXN+3];
void addedge(int u,int v){
	es[++tot].v=v;
	es[tot].nxt=head[u];
	head[u]=tot;
}
void topo_sort(){
	int h=0,w=0;
	dp[t]=ans;
	for(int i=1;i<=n;i++){
		if(dg[i]==0)q[w++]=i;
	}
	while(h<w){
		int u=q[h];h++;
		dp[u]=dp[u]*inv[dg2[u]]%MOD;
		for(int i=head[u];i;i=es[i].nxt){
			(dp[es[i].v]+=dp[u])%=MOD;
			if(--dg[es[i].v] == 0)
				q[w++]=es[i].v;
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	inv[1]=1;for(int i=2;i<=m+1;i++)inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(int i=1,a,b;i<=m;i++){
		scanf("%d%d",&a,&b);
		addedge(a,b);dg[b]++;
	}
	memcpy(dg2,dg,sizeof(dg));
	dg2[t]++;
	ans=1;
	for(int i=2;i<=n;i++)ans=ans*dg2[i]%MOD;
	
	if(t==1){
		printf("%lld\n",ans);
		return 0;
	}
	topo_sort();
	printf("%lld\n",(ans-dp[s]+MOD)%MOD);
	return 0;	
}


