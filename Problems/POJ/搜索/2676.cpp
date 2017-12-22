/*
Sudoku
题意：完成数独
分析：记录每个九宫格，每行每列所含的数字，DFS，从(8,8)搜比从(0,0)搜快很多 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
bitset<9> col[9],row[9],sq[9],vis[9];
int map[9][9];
bool Isfind;
void output(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)printf("%d",map[i][j]+1);
        printf("\n");
    }
}
void dfs(int x,int y){
    int u=x*9+y-1;//下一个待填的位置（向前退一个） 
    if(x==-1){Isfind=true;output();return;}
    if(map[x][y]!=-1){dfs(u/9,u%9);return;}
    for(int i=0;i<9&&!Isfind;i++){
        int k=(x/3)*3+y/3;
        if(!row[x][i]&&!col[y][i]&&!sq[k][i]){
            row[x][i]=col[y][i]=sq[k][i]=1;map[x][y]=i;
            dfs(u/9,u%9);
            row[x][i]=col[y][i]=sq[k][i]=0;map[x][y]=-1;
        }
    }
}
int main(){
    int cas;char q;
    scanf("%d",&cas);
    while(cas--){
    	memset(map,0,sizeof(map));
        for(int i=0;i<9;i++)vis[i]=col[i]=row[i]=sq[i]=0;
        for(int i=0;i<9;i++){
        	scanf("\n"); 
            for(int j=0;j<9;j++){
                scanf("%c",&q);
                map[i][j]=q-'1';
                if(q!='0')row[i][q-'1']=col[j][q-'1']=sq[(i/3)*3+(j/3)][q-'1']=1;
            }
        }
        Isfind=false;
        dfs(8,8);
    }
}

