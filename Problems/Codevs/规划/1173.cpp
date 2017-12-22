/*
最优贸易
分析：思路较简单，对每个点i，求出起点到i的所有路径上点的权值最小值，i到终点的所有路径上点的权值最大值，两者之差即为答案
	  但是注意这里是点的权值，而不是边的权值。
	  本来想统一两个spfa，却发现有些困难，于是copy了份代码。。。
	  另一个方法是先将原图中的环缩成点（强连通分量），得到一个DAG，
	  每个新点的买入最优为环上最小权值，卖出最优为环上最大权值，
	  然后拓扑序上DP 
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,cnt;
int v[100001];
int head1[100001],head2[100001];
int mn[100001],mx[100001];
int d[1000001];
bool pd[100001];
struct data{
	int from,to,next1,next2;
}e[1000001];
void insert(int u,int v)
{
	cnt++;
	e[cnt].to=v;e[cnt].from=u;
	e[cnt].next1=head1[u];e[cnt].next2=head2[v];
	head1[u]=cnt;head2[v]=cnt;
}
void spfa1()
{
	int t=0,w=0;
	d[0]=1;mn[1]=v[1];pd[1]=1;
	while(t<=w)
	{
		int p=head1[d[t]];
		while(p>0)
		{
			if(mn[e[p].to]>mn[d[t]]||v[e[p].to]<mn[e[p].to])
			{
				mn[e[p].to]=min(v[e[p].to],mn[d[t]]);
				if(!pd[e[p].to])d[++w]=e[p].to;
				pd[e[p].to]=1;
			}
			p=e[p].next1;
		}
		pd[d[t]]=0;
		t++;
	}
}
void spfa2()
{
	memset(pd,0,sizeof(pd));
	memset(mx,-1,sizeof(mx));
	int t=0,w=0;
	d[0]=n;mx[n]=v[n];pd[n]=1;
	while(t<=w)
	{
		int p=head2[d[t]];
		while(p>0)
		{
			if(mx[e[p].from]<mx[d[t]]||v[e[p].from]>mx[e[p].from])
			{
				mx[e[p].from]=max(v[e[p].from],mx[d[t]]);
				if(!pd[e[p].from])d[++w]=e[p].from;
				pd[e[p].from]=1;
			}
			p=e[p].next2;
		}
		pd[d[t]]=0;
		t++;
	}
}
int main()
{
	memset(mn,127,sizeof(mn));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
    for(int i=1;i<=m;i++)
    {
    	int x,y,z;
    	scanf("%d%d%d",&x,&y,&z);
    	insert(x,y);
    	if(z==2)insert(y,x);
    }
    spfa1();spfa2();
	
    int ans=0;
    for(int i=1;i<=n;i++)
		ans=max(mx[i]-mn[i],ans);
    printf("%d",ans);
	return 0;
}
/*自己的代码 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<bitset>
#include<queue>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
struct edge{
	int u,v;
};
vector<edge> es;
vector<int> g[MAXN+3];
int vw[MAXN+3],mx[MAXN+3],mn[MAXN+3],n;
void add(int u,int v){
	es.push_back((edge){u,v});
	es.push_back((edge){v,u});
	g[u].push_back(es.size()-2);
	g[v].push_back(es.size()-1);
}
queue<int> q;
bitset<MAXN+3> inq;
void canto(int u,int flag){
	inq=0;
	int e=0;
	while(!q.empty())q.pop();
	queue<int> t;
	t.push(u);q.push(u);inq[u]=1;
	while(!t.empty()){
		int k=t.front();t.pop();
		for(int i=0;i<g[k].size();i++){
			if((g[k][i]&1)==flag){
				if(!inq[e=(es[g[k][i]].v)]){
					q.push(e);inq[e]=1;t.push(e);
				}
			}
		}
	}
}
void spfa(int from,int flag,int* arr){//flag表示求最大(1)还是最小(0) 
	inq=0;while(!q.empty())q.pop();
	//if(flag)memset(arr,0,sizeof(arr));
	//else memset(arr,INF,sizeof(arr));
	for(int i=1;i<=n;i++)arr[i]=vw[i];
	canto(from,flag);
	bool canpush=false;
	while(!q.empty()){
		int t=q.front();q.pop();inq[t]=0;
		for(int i=0;i<g[t].size();i++){
			if((g[t][i]&1)==flag){//flag=1,求最大，走反向边；flag=0,求最小，走原边  
				edge &e=es[g[t][i]];canpush=false;
				//cout<<g[t][i]<<":"<<e.u<<" "<<e.v<<endl;
				if(flag){//求最大 
					if(arr[e.v]<arr[t]){
						canpush=true;
					}
				}
				else if(arr[e.v]>arr[t]){
					canpush=true;
				}
				if(canpush){
					//cout<<"!!!"<<endl;
					arr[e.v]=arr[t];
					if(!inq[e.v]){
						q.push(e.v);inq[e.v]=1;
					}
				}
				
			}
		}
	}
}
int solve(){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,mx[i]-mn[i]);
	}
	return ans;
}
void input(){
	int m,a,b,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>vw[i];
	while(m-->0){
		cin>>a>>b>>c;
		switch(c){
			case 2:
				add(b,a);
			case 1:
				add(a,b);
				break;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	input();
	//for(int i=0;i<es.size();i++)
	//	cout<<i<<":"<<es[i].u<<" "<<es[i].v<<endl;
	spfa(1,0,mn);
	//for(int i=1;i<=n;i++)cout<<mn[i]<<" ";cout<<endl;
	spfa(n,1,mx);
	//for(int i=1;i<=n;i++)cout<<mx[i]<<" ";cout<<endl;
	cout<<solve();
	return 0;
}*/ 
