/*
����������ÿ��ʯ������ȡһ��Ϊ�����뷨������һ�����Ϊ�����㣨�ɳ���Ϊʯ���ײ�������������������������Ϊʯ���߶ȡ�
		����Դ������������ĵ�����������Ϊ1��
		���������ͼ�������������ĵ�����������ΪINF��
		���ڵ�ͼ����������ʯ����������С��d���ͽ�����һ��ʯ���Ķ�������һ��ʯ���ĵײ�����������������ΪINF��
		��ͼ��ɣ�ʣ�¾�����һ���������Ȼ��������������ȥ������������ս���� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue> 
using namespace std;
const int MAXN=20*20*2,INF=0x3f3f3f3f;
struct edge{
	int u,v,c,f;
	edge(int u,int v,int c):u(u),v(v),c(c),f(0){}
};
vector<edge> es;
vector<int> g[MAXN+3];
queue<int> q;
int ds[MAXN+3],cur[MAXN+3];
int S,T;
void addedge(int u,int v,int c){
	es.push_back(edge(u,v,c));
	g[u].push_back(es.size()-1);
	es.push_back(edge(v,u,0));
	g[v].push_back(es.size()-1);
}

bool bfs(int s,int t){
	memset(ds,INF,sizeof(ds));
	while(!q.empty())q.pop();
	q.push(s);ds[s]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<g[u].size();i++){
			edge &e=es[g[u][i]];
			if(e.c-e.f==0 || ds[e.v]<INF)continue;
			ds[e.v]=ds[u]+1;
			q.push(e.v);
		}
	}
	return ds[t]<INF;
}
int dfs(int u,int a){
	if(u==T || a==0)return a;
	int flow=0,f;
	for(int &i=cur[u];i<g[u].size();i++){ 
		edge &e=es[g[u][i]];
		if(ds[e.v]==ds[u]+1 && (f=dfs(e.v,min(a,e.c-e.f)))>0){
			e.f+=f;
			es[g[u][i]^1].f-=f;
			flow+=f;
			a-=f;
			if(a==0)break;
		}
	}
	return flow;
}
int augment(){
	int ans=0;
	while(bfs(S,T)){memset(cur,0,sizeof(cur));ans+=dfs(S,INF);}
	return ans;
}
int R,C,D,cnt=0;
int mp[20+3][20+3];
bool mrk[20+3][20+3];
//����λ�� 
#define idx1(i,j) ((i-1)*C+j)
//ʯ��λ��
#define idx2(i,j) ((R*C)+(i-1)*C+j)
char ch[30];
#define sqr(x) ((x)*(x))
int main(){
	scanf("%d%d%d",&R,&C,&D);
	S=0,T=idx2(R+1,1); 
	for(int i=1;i<=R;i++){
		for(int j=1;j<=C;j++)scanf("%1d",&mp[i][j]);
	}
	for(int i=1;i<=R;i++){
		scanf("%s",ch+1);
		for(int j=1;j<=C;j++){
			mrk[i][j]=ch[j]=='L';
			if(mrk[i][j])addedge(S,idx1(i,j),1),cnt++;
		}
	}
	
	for(int i=1;i<=D;i++){
		for(int j=1;j<=C;j++){
			if(mp[i][j])
				addedge(idx2(i,j),T,INF);
			if(mp[R-i+1][j])
				addedge(idx2(R-i+1,j),T,INF);
		}
	}
	for(int i=1;i<=D;i++){
		for(int j=D+1;j<=R-D;j++){
			if(mp[j][i])
				addedge(idx2(j,i),T,INF);
			if(mp[j][C-i+1])
				addedge(idx2(j,C-i+1),T,INF);
		}
	}
	for(int x1=1;x1<=R;x1++){
    	for(int y1=1;y1<=C;y1++){
    		if(mp[x1][y1]==0)continue;
    		addedge(idx1(x1,y1),idx2(x1,y1),mp[x1][y1]);
    		int a=max(x1-D,1),b=min(x1+D,R),c=max(y1-D,1),d=min(y1+D,C);//�����c��d��Ҫ��֮ǰ��c��d���ˣ�WA�˺þ�= = 
        	for(int x2=a;x2<=b;x2++)
            	for(int y2=c;y2<=d;y2++)
            		if((x1!=x2||y1!=y2)&&mp[x2][y2]&& (sqr(x1-x2)+sqr(y1-y2)<=sqr(D)))addedge(idx2(x1,y1),idx1(x2,y2),INF);
        }
    }//cout<<g[12].size()<<endl;
    //for(int i=0;i<=T;i++){cout<<i<<" "<<g[i].size()<<endl;for(int j=0;j<g[i].size();j++)cout<<es[g[i][j]].v<<" "<<es[g[i][j]].c<<endl;}
    //cout<<cnt<<endl;
    printf("%d\n",cnt-augment());
	return 0;
}

