/*
题意：推箱子，要求箱子移动步骤最小。T为目标地，B为箱子，S为推箱子的人，要求将B推到T，步骤最少。
分析：双重bfs，箱子到达目的地，人到达箱子的前一个位置，在箱子能够达到下一个位置的同时，要保证箱子的前一个位置是可以到达的，不能够是障碍物，否则人无法去推 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cctype>
using namespace std;
char map[25][25];
const int N=1000000;
struct data{
    int sx,sy,bx,by,step;
    string ans;
}Q[2][N];
int dr[][2]={-1,0,1,0,0,-1,0,1},r,c;
char op[]={'n','s','w','e'};
int mark[25][25][4];
bool bfs(int tx,int ty,data &cc){
    if(tx<1||tx>r||ty<1||ty>c||map[tx][ty]=='#')return false;
    bool fmark[25][25];
    memset(fmark,false,sizeof(fmark));
    int bx=cc.bx,by=cc.by,st=0,ed=1;
    data a,b;
    a.sx=cc.sx;a.sy=cc.sy;a.ans=cc.ans;
    Q[1][0]=a;
    while(st!=ed){
        a=Q[1][st++];
        if(st==N)st=0;
        if(a.sx==tx&&a.sy==ty){
            cc.ans=a.ans;
            cc.sx=tx;cc.sy=ty;
            return true;
        }
        for(int i=0;i<4;i++){
            b.sx=a.sx+dr[i][0];
            b.sy=a.sy+dr[i][1];
            if(b.sx>=1&&b.sx<=r&&b.sy>=1&&b.sy<=c&&!(b.sx==bx&&b.sy==by)&&(map[b.sx][b.sy]=='.'||map[b.sx][b.sy]=='T')&&!fmark[b.sx][b.sy]){
                fmark[b.sx][b.sy]=true;
                b.ans=a.ans+string(1,(char)op[i]);
                Q[1][ed++]=b;
                if(ed==N)ed=0;
            }
        }
    }
    return false;
}
int main(){
    int st,ed,ca=0;
    while(scanf("%d%d",&r,&c),r+c>0){
        data a,b;
        for(int i=1;i<=r;i++){
            scanf("%s",map[i]+1);
            for(int j=1;j<=c;j++){
                if(map[i][j]=='S')map[a.sx=i][a.sy=j]='.';
                else if(map[i][j]=='B')map[a.bx=i][a.by=j]='.';
            }
        }
        memset(mark,-1,sizeof(mark));
        a.step=0;
        a.ans="";
        Q[0][st=ed=0]=a;
        ed++;
        memset(mark[a.bx][a.by],0,4*sizeof(int));
        printf("Maze #%d\n",++ca);
        bool flag=false;
        string ans;
        while(st!=ed){
            a=Q[0][st++];
            if(st==N)st=0;
            if(map[a.bx][a.by]=='T'){
                flag=true;
                ans=a.ans;
                break;
            }
            for(int i=0;i<4;i++){
                int x=a.bx+dr[i][0],y=a.by+dr[i][1];
                if(x>=1&&x<=r&&y>=1&&y<=c&&(map[x][y]=='.'||map[x][y]=='T')&&(mark[x][y][i]>a.step+1||mark[x][y][i]==-1)){
                    b=a;
                    if(bfs(a.bx-dr[i][0],a.by-dr[i][1],b)){
                        b.step++;
                        b.ans.append(1,(char)toupper(op[i]));
                        b.sx=b.bx;
                        b.sy=b.by;
                        b.bx=x;
                        b.by=y;
                        Q[0][ed++]=b;
                        if(ed==N)ed=0;
                        mark[x][y][i]=b.step;
                    }
                }
            }
        }
        if(!flag)printf("Impossible.\n\n");
        else printf("%s\n\n",ans.c_str());
    }
    return 0;
}
