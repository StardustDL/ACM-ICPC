/*
施工方案第二季
分析：先求最小生成树，在树上找最长链，其长度中点到两边距离最大值为第二问答案 
*/ 
/*#include<iostream>
#include<cstring>
#include<vector>
#include<bitset>
#include<queue>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN=100000,MAXM=200000;
struct edge{
	int u,v,w;
};
vector<edge> es;
vector<int> g[MAXN+3];
bitset<2*MAXM+3> in;
queue<int> q;
int r[MAXM+3],n,m,d[MAXN+3],ph[MAXN+3];
struct uniset{
	int pa[MAXN+3];
	void init(){memset(pa,0,sizeof(pa));}
	int find(int x){return pa[x]==0?x:pa[x]=find(pa[x]);}
	bool unions(int x,int y){x=find(x),y=find(y);if(x==y)return false;pa[x]=y;return true;}
}S;
void add(int u,int v,int w){
	es.push_back((edge){u,v,w});
	g[u].push_back(es.size()-1);
	es.push_back((edge){v,u,w});
	g[v].push_back(es.size()-1);
}
bool cmp(int i,int j){
	return es[i].w<es[j].w;
}
int kruskal(){
	for(int i=0;i<es.size();i++)r[i]=i;
	sort(r,r+es.size(),cmp);S.init();
	int ans=0;in=0;
	for(int i=0;i<es.size();i++){
		//if(r[i]&1)continue;
		edge &e=es[r[i]];
		if(S.unions(e.u,e.v))ans+=e.w,in[r[i]]=in[r[i]^1]=1;
	}
	return ans;
}
int bfs(int from){
	memset(d,0,sizeof(d));
	int mx=0,p=from;
	q.push(from);
	while(!q.empty()){
		int t=q.front();q.pop();
		//printf("%d\n",t);
		//cout<<t<<endl;
		for(int i=0;i<g[t].size();i++){
			//printf("%d\n",g[t][i]);
			if(!in[g[t][i]])continue;
			edge &e=es[g[t][i]];
			if(d[e.v]!=0)continue;
			//cout<<e.v<<endl;
			d[e.v]=d[t]+e.w;
			ph[t]=e.v;
			if(d[e.v]>mx){
				mx=d[e.v];p=e.v;
				//cout<<p<<" "<<mx<<endl;
			}
			q.push(e.v);
			//printf("%d\n",e.v);
		}
		//cout<<"!!!"<<endl;
	}
	return p;
}
int main(){
	cin>>n>>m;int a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		add(a,b,c);
	}
	cout<<kruskal()<<endl;
	int t=bfs(1);//cout<<"!!!"<<endl;
	//cout<<t<<endl;
	//cout<<"!!!"<<endl;
	int k=bfs(t);
	//cout<<k<<endl;
	int x=t;
	//cout<<d[k]<<endl;
	while(d[ph[x]]<d[k]/2)x=ph[x];
	cout<<max(d[k]-d[x],d[ph[x]]);
	return 0;
}*/
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm> 
using namespace std;
int n, m;
struct edge{int x,y,z;}a[200001];
struct node{int p,w;}e;//p是点，w为权 
vector<node>h[100001];
int p[100001],d[100001],b[100001];//d最大深度，b最大深度的点;
bool cmp(const edge &a, const edge &b){return a.z<b.z;}
int search(int a){return p[a]==0?a:p[a]=search(p[a]);}
void treedp(int c){
     int i,j;d[c]=-1;
     for(i=0;i<h[c].size();i++)
         if(d[j=h[c][i].p]==0){//不回访 
		 	treedp(j);p[j]=c;
            if(d[j]+h[c][i].w>d[c]){
               d[c]=d[j]+h[c][i].w;
               b[c]=b[j];
            }
         }
     if(d[c]<0){d[c]=0;b[c]=c;}//叶子
} 
int main(){
    int i,u,v,j;
    long long s=0,ans;
    cin>>n>>m;
    for(i=0;i<m;i++)cin>>a[i].x>>a[i].y>>a[i].z;
    sort(a,a+m,cmp);
    for(i=j=0;j<n-1;i++){
        u=search(a[i].x);v=search(a[i].y);
        if(u==v)continue;
        else{
            p[u]=v;
            e.p=a[i].x;
            e.w=a[i].z;
            s+=a[i].z;
            h[a[i].y].push_back(e);
            e.p=a[i].y;
            h[a[i].x].push_back(e);
            j++;
        }
    }
    treedp(1);
    v=b[1];
    memset(d,0,sizeof(d));
    treedp(v);
    u=b[v];
    i=u;
    while(d[p[i]]<=d[v]/2)i=p[i];
    ans=min(d[v]-d[i],d[p[i]]);
    cout<<s<<endl<<ans<<endl;
    return 0;
}
