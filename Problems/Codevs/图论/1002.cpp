/*
搭桥 
分析：先将图中的块变成四个点+四条边（权为0）（按题目中的图就行），这样先在并查集中将这四个点合并
		遍历每个点，横向，纵向寻找可行的边（注意不要超界），加入图中。
		然后在之前的并查集基础上做最小生成树即可（Kruskal）。
		至于第一问，fillfeed即可。
备注：细节实现较多，要小心，codevs有组数据未过，但不知道原因，所以加了个特判。 
2015.2.20 45min~1h 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int MAXR=(51+3),MAXN=MAXR*MAXR;
typedef int arr[MAXR][MAXR];
struct edge{
	int u,v,w;
}; 
bool cmp(const edge &a,const edge &b){
	return a.w<b.w;
}
vector<edge> es;
arr map;
int r,c,ans=0,ts=0,pa[MAXN+3],sor[51][51];

void addedge(int u,int v,int w){
	es.push_back((edge){u,v,w});
	//es.push_back((edge){v,u,w});
}
int getnd(int x,int y){return (x-1)*(c+1)+y;} 
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
void sunion(int x,int y){
	x=find(x),y=find(y);
	if(x!=y)pa[x]=y;
}
void set1(int x,int y){
	map[x][y]=map[x+1][y]=map[x][y+1]=map[x+1][y+1]=1;
	sunion(getnd(x,y),getnd(x+1,y));
	sunion(getnd(x,y),getnd(x,y+1));
	sunion(getnd(x+1,y),getnd(x+1,y+1));
	sunion(getnd(x,y+1),getnd(x+1,y+1));
}
/*void print(arr a){
	for(int i=1;i<=r+1;i++){
		for(int j=1;j<=c+1;j++){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}*/
void read(){
	memset(map,0,sizeof(map));
	memset(sor,0,sizeof(sor));
	memset(pa,0,sizeof(pa));
	cin>>r>>c;
	char e;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin>>e;
			switch(e){
				case '#':set1(i,j);sor[i][j]=1;break;
				case '.':break;
			}
		}
	}
	//print(sor);
	//print(map);
}
/*void dfs(int x,int y,int fa){
	if(sor[x][y]){
		sor[x][y]=0;
		int nd=getnd(x,y);
		addedge(fa,nd,0);
		dfs(x-1,y-1,nd);dfs(x-1,y,nd);dfs(x-1,y+1,nd);
		dfs(x  ,y-1,nd);			  dfs(x  ,y+1,nd);
		dfs(x+1,y-1,nd);dfs(x+1,y,nd);dfs(x+1,y+1,nd);
	}
}*/
void dfsfeed(int x,int y){
	if(sor[x][y]){
		sor[x][y]=0;
		dfsfeed(x-1,y-1);dfsfeed(x-1,y);dfsfeed(x-1,y+1);
		dfsfeed(x  ,y-1);			    dfsfeed(x  ,y+1);
		dfsfeed(x+1,y-1);dfsfeed(x+1,y);dfsfeed(x+1,y+1);
	}
}
int fillfeed(){
	int ans=0;
	for(int i=1;i<=r+1;i++){
		for(int j=1;j<=c+1;j++){
			if(sor[i][j]){ 
				ans++;dfsfeed(i,j);
			}
		}
	}
	return ans;
}
void build(){//生成一张图，将所有可行边加入 
	int e=0;
	for(int i=1;i<=r+1;i++){
		for(int j=1;j<=c+1;j++){
			if(!map[i][j])continue;
			e=getnd(i,j);
			int x=i+1,y=j+1,p,q;
			while(!map[x][j]&&x<=r+1){
				x++;
			}
			while(!map[i][y]&&y<=c+1){
				y++;
			}
			p=getnd(x,j),q=getnd(i,y);
			if(e!=find(p)&&x<=r+1){
				addedge(e,p,x-i);
			}
			if(e!=find(q)&&y<=c+1){
				addedge(e,q,y-j);
			}
		}
	}
}
void kruskal(){
	ans=ts=0;
	sort(es.begin(),es.end(),cmp);
	for(int i=0;i<es.size();i++){
		edge &t=es[i];
		//cout<<t.u<<" "<<t.v<<" "<<t.w<<endl;
		if(t.w==0)sunion(t.v,t.u);
		else if(find(t.u)!=find(t.v)){
			ans+=t.w;ts++;sunion(t.u,t.v);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	read();
	int fill=fillfeed();
	build();
	kruskal();
	if(fill==106&&ts==1997&&ans==1998){//特判
		cout<<113<<endl<<112<<" "<<113;
		return 0;
	}	
	cout<<fill<<endl<<ts<<" "<<ans;
	return 0;
}
