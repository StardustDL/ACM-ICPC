/*
Currency Exchange
���⣺�������ֻ��ң�ĳЩ����֮��ɶһ����������ֶһ�ʱ�Ļ��ʺ������ѣ��κζһ�����˫��ģ�������������Ļ��ʺ������ѿ��ܲ�ͬ������֪������ӵ�еĻ������ֻࣨӵ��һ�֣������������Ƿ����ͨ�����ҽ��һ����ص������ֺ�Ǯ���������ӡ�
�������൱����һ����Ȩ����Ϊʲô�أ�
	  ���Լ��ı��ֳ��������������������ô����Բ�ͣ���߻�·�������Լ����еļ�ֵ��
	  ����Ϊ���е�·����˫��ģ����Ե����еļ�ֵ���ӵ��㹻��֮����һ�����Իص��Լ�ԭ�еı��ֵġ�
	  ����Ϊ������ʹ��ֵ�ﵽ��������Ի�ȥ֮���ֵһ�����ӡ����Ա���ת��Ϊ�ж��Ƿ��������� 
	  Ȼ�������������е����⣬���ɳڲ�����û�б䣬�޸�һ����������
	  �л���
	  	1.ÿ��һ������Ӿ�cnt[i]++������һ��cnt[i]>n����һ���л�
	  	2.��¼��S��i����·�ı�����ÿ���ɳڣ���cnt[v]=cnt[u]+1������һ��cnt[i]>n����һ���л�
		  ��Ϊһ������>n����һ���б��ཻ��ͬһ�㣬������л������ⲻ�Ǳ�Ҫ�����ɣ�
		��ʵ��ǰ��ACʱ��63ms������ʱ��32���룬�ٶ���߽�һ�����Ż������� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<queue>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
struct edge{
	int u,v;
	double rate,cost;
	edge(int u,int v,double rate,double cost):u(u),v(v),cost(cost),rate(rate){}
};
vector<edge> es;
vector<int> g[MAXN+3];
queue<int> q;
bitset<MAXN+3> inq;
double dis[MAXN+3],v;
int cnt[MAXN+3];
int n,s;
void addedge(int u,int v,double r,double c){
	es.push_back(edge(u,v,r,c));
	g[u].push_back(es.size()-1);
}
bool spfa(int from,double val){
	while(!q.empty())q.pop();
	inq=0;inq[from]=1;q.push(from);
	memset(cnt,0,sizeof(cnt));
	memset(dis,0,sizeof(dis));
	dis[from]=val;
	cnt[from]=1;
	while(!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(dis[e.v]<(dis[u]-e.cost)*e.rate){
				dis[e.v]=(dis[u]-e.cost)*e.rate;
				if((cnt[e.v]=cnt[u]+1)>n)return true;
				if(!inq[e.v]){
					inq[e.v]=1;
					q.push(e.v);
				}
			}
		}
		if(dis[from]>v)return true;
	}
	return false;
}
void input(){
	int m,a,b;
	double rab,cab,rba,cba;
	scanf("%d%d%d%lf",&n,&m,&s,&v);
	es.clear();
	for(int i=1;i<=n;i++)g[i].clear();
	while(m--){
		scanf("%d%d%lf%lf%lf%lf",&a,&b,&rab,&cab,&rba,&cba);
		addedge(a,b,rab,cab);
		addedge(b,a,rba,cba);
	}
}
int main(){
	input();
	if(spfa(s,v))puts("YES");
	else puts("NO");
	return 0;
}

