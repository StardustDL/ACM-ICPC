/*
Dungeon Master
题意：三维行走
分析：BFS 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=30;
int d[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
bitset<MAXN+3> vis[MAXN+3][MAXN+3];
char map[MAXN+3][MAXN+3][MAXN+3];
int l,m,n;
inline bool judge(int x,int y,int z){
	return x>=0&&x<l&&y>=0&&y<m&&z>=0&&z<n&&!vis[x][y][z]&&map[x][y][z]!='#';
}
struct node{
    int x,y,z,step;
    node(int x,int y,int z,int d):x(x),y(y),z(z),step(d){}
};
queue<node>q;
int BFS(int x,int y,int z){
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)vis[i][j]=0;
    while(!q.empty())q.pop();
    q.push(node(x,y,z,0));
    while(!q.empty()){
        node u=q.front();q.pop();
        if(map[u.x][u.y][u.z]=='E')return u.step;
        for(int i=0;i<6;i++){
            node v=node(u.x+d[i][0],u.y+d[i][1],u.z+d[i][2],u.step+1);
            if(judge(v.x,v.y,v.z)){
                vis[v.x][v.y][v.z]=1;
                q.push(v);
            }
        }
    }
    return 0;
}
int main(){
    while(~scanf("%d%d%d%*c",&l,&m,&n)){
        memset(map,'.',sizeof(map));
        if(!m&&!n&&!l)break;
        int sx,sy,sz;
        for(int i=0;i<l;i++)
            for(int j=0;j<m;j++){
                scanf("%s",map[i][j]);
                for(int k=0;k<n;k++)
                    if(map[i][j][k]=='S')sx=i,sy=j,sz=k;
            }
        int step=BFS(sx,sy,sz);
        if(step)printf("Escaped in %d minute(s).\n",step);
        else printf("Trapped!\n");
    }
    return 0;
}

