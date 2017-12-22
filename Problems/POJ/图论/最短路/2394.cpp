/*
Checking an Alibi
���⣺һ���ط���F��ũ�����ֱ�Ϊf1,f2,...,fp�����У�f1�ǹȲ֣��м�ֻţվ����Щũ���ϣ���������û�¸ɾ�����ȥ͵�Թ��ӡ���ϧ�������ǳԵ�����֮ǰM�룬�и�����ͷ�����ǵ�λ���������ˣ�fi��fj֮����·����ͨ(����ͼ)������֪��������·����ʱ��t�����ǻ�֪���ܹ���Cֻţ�����Ǹ���վ�ڲ�ͬ������ͬ��ũ���ϣ�������һ���ж���ͷţ���ܻ�ȥ͵�Թ��ӣ������������ǵ���������
   ����:
   f(ũ����Ŀ)
   p(��f��ũ��֮���p��·��,ע��������ͼ)
   c(ţ����Ŀ)  
   m(ţ�����͵�Ե�����,��ô�����Ȳֵ���̾������С�ڻ����m)
   p��·������Ϣ����� �յ� Ȩ��
   cͷţ����Ϣ(��i�м���ʾ���Ϊi��ţ���ڵ�ũ�����)
������dijkstra�����·��Ȼ�󽫵��Ȳֵ�ʱ��С�ڵ���m��ţ���
	  ���رߣ����ܱ�����2N���𣬾Ͳ����� 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<bitset> 
using namespace std;
const int MAXN=500,INF=0x3f3f3f3f;
vector<int> to[MAXN+3];
vector<int> wt[MAXN+3];
void addedge(int u,int v,int w){
	to[u].push_back(v);
	wt[u].push_back(w);
}
int d[MAXN+3];
struct node{int p,d;node(int p,int d):p(p),d(d){}bool operator < (const node &t)const{return d>t.d;}};
priority_queue<node> q;
void dijkstra(int s){
	memset(d,INF,sizeof(d));
	d[s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		node t=q.top();q.pop();
		if(t.d>d[t.p])continue;
		for(int i=0;i<to[t.p].size();i++){
			if(d[to[t.p][i]]>d[t.p]+wt[t.p][i]){
				d[to[t.p][i]]=d[t.p]+wt[t.p][i];
				q.push(node(to[t.p][i],d[to[t.p][i]]));
			}
		}
	}
}
int f,p,c,m;
vector<int> ans;
int main(){
	scanf("%d%d%d%d",&f,&p,&c,&m);
	for(int a,b,w;p;p--){
		scanf("%d%d%d",&a,&b,&w);
		addedge(a,b,w);
		addedge(b,a,w);
	}
	dijkstra(1);
	for(int t,i=1;i<=c;i++){
		scanf("%d",&t);
		if(d[t]<=m)ans.push_back(i);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)printf("%d\n",ans[i]); 
	return 0;
}

