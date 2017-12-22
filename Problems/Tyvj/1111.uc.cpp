#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<vector>
#include<bitset>
using namespace std;
const int MAXN=200;
struct edge{
	int u,v;
};
int ans=0,low[MAXN+3],pre[MAXN+3],time=0;
vector<edge> es;
stack<int> sta;
void dfs(int u,int fa){
	low[u]=pre[u]=++time;
	
}
int main(){
	
}
