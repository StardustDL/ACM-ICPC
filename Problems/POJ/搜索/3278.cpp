/*
Catch That Cow
题意：一个数N，三种操作+1，-1，*2，问最少多少步变为K
分析：最简单BFS 
*/
#include<queue>
#include<algorithm>
#include<cstdio>
#include<bitset>
#include<cstring> 
using namespace std;
const int MAXN=100000; 
bitset<MAXN+3> vis;
queue<int> q;
int d[MAXN+3],n,k;
int bfs(int x){
	while(!q.empty())q.pop();
    vis=0;memset(d,0,sizeof(d));
    vis[x]=1;
    q.push(x);
    while(!q.empty()){
        x=q.front();q.pop(); 
        if(d[k]!=0)return d[k];
        if(x>0&&!vis[x-1]){vis[x-1]=1;q.push(x-1);d[x-1]=d[x]+1;}
        if(x<MAXN&&!vis[x+1]){vis[x+1]=1;q.push(x+1);d[x+1]=d[x]+1;}
        if(x<=(MAXN>>1)&&!vis[x<<1]){vis[x<<1]=1;q.push(x<<1);d[x<<1]=d[x]+1;}
    }
}
int main(){
	scanf("%d%d",&n,&k);
    printf("%d\n",bfs(n));
    return 0;
}
