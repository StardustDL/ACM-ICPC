/*

*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<bitset> 
#include<queue>
using namespace std;
const int MAXN=100; 
int n,con[MAXN+3][9],move[MAXN+3][9],sta[9];//move[i][j]记录第i个方块在8个方向上分别比第1个方块多了几个单位,sta[i]记录每个方向上离第1个方块最远的距离
bitset<MAXN+3> vis;
queue<int>q;
map<int,int> pos;//pos[o]保存号码为o的方块所在的输入时的次序i,由于序号的大小范围并没有给出
bool solve(){
   	while(!q.empty())q.pop();vis=0;
   	q.push(1);vis[1]=1;
   	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=1;i<=8;i++){
			int nxt=pos[con[u][i]];//取出u的这位邻居的读入时的序号
			if(con[u][i]&&pos[con[nxt][((i+1)^1)-1]]!=u)return false;//判断这位nxt对应的这维上的反方向的邻居是否是u，如果不是，说明输入不合法
			if(con[u][i]&&!vis[nxt]){
				q.push(nxt);vis[nxt]=1;
				memcpy(move[nxt],move[u],sizeof(move[u]));//用u更新next的move
				move[nxt][i]++;//next比now在i方向上多一个单位
			}
		}
	}
	for(int i=1;i<=n;i++)if(!vis[i])return false;//判断是否是不合法情形2：如果此时还有点未入队，说明它在另一个连通块里
	return true;
}
int main(){
	int T,t;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		pos.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&t);pos[t]=i;//号码为t的方块是第i个输入的(离散化) 
			for(int j=1;j<=8;j++){
				scanf("%d",&t);con[i][j]=t;//读入四个维上共八个方向的邻居
			}
		}
		memset(move,0,sizeof(move));
		if(!solve()){puts("Inconsistent");continue;}
		memset(sta,0,sizeof(sta));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=8;j++){
				sta[j]=max(sta[j],move[i][j]);//找出各个方向上的最大值，存入sta
			}
		}
		printf("%d\n",(sta[1]+sta[2]+1)*(sta[3]+sta[4]+1)*(sta[5]+sta[6]+1)*(sta[7]+sta[8]+1));//同一维上相反的方向上的sta值要相加，这是显然的。并且由于第1个方块也算1个单位，所以都要加1
	}
}
