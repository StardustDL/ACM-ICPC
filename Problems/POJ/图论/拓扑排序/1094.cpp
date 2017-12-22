/*
Sorting It All Out
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<bitset>
using namespace std;
struct edge{
	int u,v;
	edge(int u,int v):u(u),v(v){}
};
vector<edge> es;
vector<int> g[27];
bitset<1003> can=0;
int d[27],d0[27],n;
queue<int>cur,ans;
void add(char x,char y){
	es.push_back(edge(x-'A'+1,y-'A'+1));
	g[x-'A'+1].push_back(es.size()-1);
}
int topo(){
	while(!ans.empty())ans.pop();
	for(int i=1;i<=n;i++)d[i]=d0[i];
	for(int i=1;i<=n;i++)if(d[i]==0)cur.push(i);
	bool flg=true;//记录是否会出现多解，即拓扑排序中是否会有超过1点在当前队列中 
	while(!cur.empty()){
		if(cur.size()>1)flg=false;
		int k=cur.front();cur.pop();
		ans.push(k);
		for(int i=0;i<g[k].size();i++){
			int t=g[k][i];
			if(!can[t])continue;
			if(--d[es[t].v]==0)cur.push(es[t].v);
		}
	}
	if(ans.size()<n)return -1;//若答案序列少于n个，就说明有环 
	if(flg)return 1;
	return 0;
}
bool input(){
	int m;char x,z; 
	scanf("%d %d",&n,&m);
	if(n==0&&m==0)return false;
	while(!cur.empty())cur.pop();
	can=0;
	es.clear();
	for(int i=1;i<=n;i++)g[i].clear();
	for(int i=1;i<=m;i++){
		scanf("\n%c<%c",&x,&z);
		add(x,z);
	}
}
void solve(){
	memset(d0,0,sizeof(d0));
	for(int i=0;i<es.size();i++){
		d0[es[i].v]++;
		can[i]=1;
		int k=topo();
		if(k==-1){
			printf("Inconsistency found after %d relations.",i+1);
			return;
		}
		else if(k==1){
			printf("Sorted sequence determined after %d relations: ",i+1);
			while(!ans.empty()){
				putchar((char)(ans.front()+'A'-1));ans.pop();
			}
			putchar('.');
			return;
		}
	}
	printf("Sorted sequence cannot be determined.");
}
int main(){
	while(input()){
		solve();
		puts("");
	}
	return 0;
}

