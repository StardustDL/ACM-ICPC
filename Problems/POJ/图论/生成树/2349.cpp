/*
Arctic Network
���⣺�����ֲ�ͬ��ͨ�ż�����������ͨ�ŵ���������֮������������磬�������ߵ�ͨ�ŵĳ���ֻ�ܺ;��벻����D�ĳ�����ϵ�����ߵ������Խ�ߣ����������DԽ�󣩣����Ѿ�Խ����֪���ߵ����Ŀm��������С��D��
����������MST��Ȼ��ѡ��MST�е�m��ıߣ�
	  ��Ҫ����С�������ֳ�m�ݣ���ɾ��m-1���ߣ��õ�m����ͨ�������ؼ���ɾ����Щ���أ���ĿҪ����С��D���ʰѹ�����С�������ıߴӴ�С����ɾ��ǰm-1���ߣ���m���߼���Ҫ�����СD�� 
*/
#include<cstring> 
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#define sqr(x) ((x)*(x)*1.0)
#define dist(i,j) (sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]))) 
using namespace std;
const int MAXN=500;
struct edge{
	int u,v;
	double w;
	bool operator <(const edge &t)const{
		return w<t.w;
	}
	edge(int u,int v,double w):u(u),v(v),w(w){}
};
struct uniset{
	int pa[MAXN+3];
	void init(){memset(pa,0,sizeof(pa));}
	int find(int x){
		return pa[x]==0?x:pa[x]=find(pa[x]);
	}
	bool unions(int a,int b){
		if(find(a)==find(b))return false;
		else pa[find(a)]=find(b);
		return true;
	}
}us;
vector<edge> es;vector<edge> ans;
double dis[MAXN+3][MAXN+3]; 
int x[MAXN+3],y[MAXN+3];
int s,p;
void init(){
	ans.clear();es.clear();us.init();
	scanf("%d%d",&s,&p);
	for(int i=1;i<=p;i++)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=p;i++){
		for(int j=1;j<i;j++){
			es.push_back(edge(i,j,dist(i,j)));
		}
	}
}
void kruskal(){
	sort(es.begin(),es.end());
	for(int i=0;i<es.size();i++)
		if(us.unions(es[i].u,es[i].v))ans.push_back(es[i]);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		init();
		kruskal();
		printf("%.2f\n",ans[ans.size()-s].w);
	}
	return 0;
}

