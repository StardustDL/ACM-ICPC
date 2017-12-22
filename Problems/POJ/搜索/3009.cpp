/*
Curling 2.0
���⣺һ����ֻ����ֱ�ߣ���ֻ��������ʯͷ��ʱ�����ͣ����������������ʯͷ������ʧ����һ��ֱ��ֻ��һ���������ٲ�����
����������������10ʱ����Ϊ�ǲ����ߵ��ˣ��⸴�ӶȾ����˴��ļ�С������ֱ�ӱ���ÿ��·������Ҳ���ᳬʱ
*/
#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;
const int MAXN=30,d[4][2]={{-1,0},{0,1},{1,0},{0,-1}}; 
int map[MAXN+3][MAXN+3];
int w,h,sx,sy,ex,ey,step,steps,fin;
inline bool judge(int x,int y){
	return x>=0&&x<h&&y>=0&&y<w&&map[x][y]!=1;
}
void dfs(int x,int y){
	if(step>10)return;
    for(int i=0;i<4;i++){
        int nx=x+d[i][0],ny=y+d[i][1],ok=0;
        while(judge(nx,ny)){
            ok=1;
            if(nx==ex&&ny==ey)if(step<steps)steps=step;
            nx+=d[i][0],ny+=d[i][1];
        }
        if(map[nx][ny]==1&&ok){
            step++;map[nx][ny]=0;
            dfs(nx-d[i][0],ny-d[i][1]);
            step--;map[nx][ny]=1;
        }
    }
}
int main(){
    while(~scanf("%d%d",&w,&h)&&w&&h){
        memset(map,0,sizeof(map));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                scanf("%d",&map[i][j]);
                if(map[i][j]==2)sx=i,sy=j;
                else if(map[i][j]==3)ex=i,ey=j;
            }
        }
        steps=1000000;
        step=1;
        dfs(sx,sy);
        printf("%d\n",steps>10?-1:steps);
    }
    return 0;
}
