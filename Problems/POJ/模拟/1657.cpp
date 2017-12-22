/*
Distance on Chessboard
题意：给棋盘上的起始点和终止点，求王、后、车、象的最短距离
分析：分类讨论，直接计算 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
    int t;
    scanf("%d", &t);
    getchar();
    while(t--){
        int x1=getchar()-'a'+1,y1=getchar()-'0';
        getchar();
        int x2=getchar()-'a'+1,y2=getchar()-'0';
        int x=abs(x1-x2),y=abs(y1-y2);
        getchar();
        if(x==0&&y==0){printf("0 0 0 0\n");continue;}
        printf("%d ",max(x,y));
        if (x==y||x==0||y==0)printf("1 ");
        else printf("2 ");
        if(x==0||y==0)printf("1 ");
        else printf("2 ");
        if((x+y)&1)printf("Inf\n");
        else if (x==y)printf("1\n");
        else printf("2\n");
    }
    return 0;
}

