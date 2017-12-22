/*
Nearest number - 2
题意：给一个矩阵，将所有0点，改为矩阵中离他最近的非0值，若有多个，不修改
分析：对每个0点BFS，注意细节，下面代码使用循环队列 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=50000;
int map[300][300],ans[300][300],po[N][2],stk[N][3];
int dr[][2]={0,1,0,-1,1,0,-1,0};
bool mark[300][300];
inline void newnode(int pos,int x,int y,int t){
	stk[pos][0]=x;
	stk[pos][1]=y;
	stk[pos][2]=t;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
    	int x,y,tx,ty,st,ed,num=0,t;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                scanf("%d",&map[i][j]);
                if(!map[i][j]){
                    po[num][0]=i;
                    po[num][1]=j;
                    num++;
                }
            }
        memcpy(ans,map,sizeof(map));
        for(int i=0;i<num;i++){
            st=0,ed=1;
            newnode(0,po[i][0],po[i][1],0);
            int minstep=0,tp=0;
            memset(mark,false,sizeof(mark));
            while(st!=ed){
                x=stk[st][0];y=stk[st][1];t=stk[st][2];
                if(++st==N)st=0;
                if(map[x][y]){
                    if(minstep==0)minstep=t,tp=map[x][y];
                    else if(minstep==t){tp=0;break;}
                }
                else if(minstep==0||minstep>t){
                    for(int j=0;j<4;j++){
                        tx=x+dr[j][0];
                        ty=y+dr[j][1];
                        if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&!mark[tx][ty]){
                            mark[tx][ty]=true;
                            newnode(ed,tx,ty,t+1);
                            if(++ed==N)ed=0;
                        }
                    }
                }
            }
            ans[po[i][0]][po[i][1]]=tp;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<n;j++)printf("%d ",ans[i][j]);
            printf("%d\n",ans[i][n]);
        }
    }
    return 0;
}
