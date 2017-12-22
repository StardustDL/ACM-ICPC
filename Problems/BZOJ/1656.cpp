/*
[Usaco2006 Jan]The Grove 树木
分析：从连通块任意一点连出去一条射线，然后计算穿过射线一次再回到起点的最小步数，同时应该限制只能从射线的一端走向另一端 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int dx[8]={0,0,1,1,1,-1,-1,-1},dy[8]={1,-1,0,1,-1,0,1,-1};
int n,m,bx,by;
int d[2][55][55],qx[5005],qy[5005];
bool mp[55][55],mark[55][55],flag[5005];
void bfs(){
    int t=0,w=1;
    d[0][bx][by]=0;
    qx[0]=bx;qy[0]=by;
    while(t!=w){
    	int x=qx[t],y=qy[t],f=flag[t];t++;
        for(int i=0;i<8;i++){
            int nowx=x+dx[i],nowy=y+dy[i];
            if(mp[nowx][nowy]||nowx<1||nowy<1||nowx>n||nowy>m)continue;
            if(mark[x][y]&&nowy<=y)continue;//只跨过一次，因为是一个环，强制规定一个跨过的方向 
            if(mark[nowx][nowy]&&nowy>y){
                if(d[1][nowx][nowy]==-1){
                    d[1][nowx][nowy]=d[0][x][y]+1;
                    qx[w]=nowx;qy[w]=nowy;flag[w]=1;w++;
                }
            }
            else if(d[f][nowx][nowy]==-1){
                d[f][nowx][nowy]=d[f][x][y]+1;
                qx[w]=nowx;qy[w]=nowy;flag[w]=f;w++;
            }
        }
    }
}
int main(){
    memset(d,-1,sizeof(d)); 
    scanf("%d%d",&n,&m);
    int tx,ty;
    for(int i=1;i<=n;i++){
        char ch[55];scanf("%s",ch+1);
        for(int j=1;j<=m;j++)
            if(ch[j]=='X'){mp[i][j]=1;tx=i;ty=j;}
            else if(ch[j]=='*'){bx=i;by=j;}
    }
    for(int i=0;tx+i<=n;i++)mark[tx+i][ty]=1;
    bfs();
    printf("%d",d[1][bx][by]);
    return 0;
}
