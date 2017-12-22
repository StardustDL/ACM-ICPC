/*
Bovine Birthday
题意：求某天是星期几。
分析：列个式子 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char name[][12] = { "monday", "tuesday", "wednesday","thursday", "friday", "saturday", "sunday"};
int main(){
    int d,m,y,a;
    while(scanf("%d%d%d",&y,&m,&d)!=EOF){
        if(m==1||m==2){m+=12;y--;}
        if((y<1752)||(y==1752&&m<9)||(y==1752&&m==9&&d<3))
            a=(d+2*m+3*(m+1)/5+y+y/4+5)%7;
        else
            a=(d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
        puts(name[a]);
    }
    return 0;
}
