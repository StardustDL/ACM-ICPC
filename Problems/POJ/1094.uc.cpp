#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
const int MAXN=26;
struct edge{
	int u,v;
};//es[701],A(26,2)=26!/(26-2)!=650
vector<edge> es;
vector<int> g[MAXN+3];
stack<int> d0;
int n,deg[MAXN+3],m;
char a,b,c;
void add(int u,int v){
	es.push_back((edge){u,v});
	g[u].push_back(es.size()-1);
}
bool read(){
	cin>>n>>m;
	return n!=0;
}
void init(){
	es.clear();
	for(int i=1;i<=n;i++)g[i].clear();
	while(!d0.empty())d0.pop();
	memset(deg,0,sizeof(deg));
}
int main(){
	ios::sync_with_stdio(false);
	while(read()){
		init();
		for(int i=1;i<=m;i++){
			
		}
	}
}
