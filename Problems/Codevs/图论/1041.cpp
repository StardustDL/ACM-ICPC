/*
Car的旅行路线
分析：首先如何由三个点确定第四个点：找到直角的点，可以勾股定理，或者向量点积，然后就可以推出公式了：令(x0,y0)为直角顶点坐标，x=x1+x2-x0. y=y1+y2-y0。
		第二个问题：暴力建图，最短路，最短路可以四遍dijkstra，也可以简单Floyd，400^3基本能过，另外堆优化的dijkstra并不一定快，其效率是MlogN，此题中基本上是完全图，所以M接近N^2，并不优，朴素dijkstra=O(N^2)
*/
#include<cmath>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define sqr(x) ((x)*(x)) 
const int MAXN=100;
const double INF=100000000.0; 
int price[MAXN+3];
int x[4*MAXN+3],y[4*MAXN+3];
double dis[4*MAXN+3][4*MAXN+3];
int s,t,a,b,len,tx[4], ty[4],d[3];
double getdis(int x1,int y1,int x2,int y2){
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}
double solve(){
    double ans=INF;
    scanf("%d%d%d%d",&s,&t,&a,&b);
    a--,b--;
    for(int i=0;i<4*s;i++)
        for(int j=0;j<4*s;j++)
            dis[i][j]=INF;
    for(int i=0;i<s;i++){
        scanf("%d%d%d%d%d%d%d",&tx[0],&ty[0],&tx[1],&ty[1],&tx[2],&ty[2],&len);
        d[0]=sqr(tx[0]-tx[1])+sqr(ty[0]-ty[1]);
        d[1]=sqr(tx[2]-tx[0])+sqr(ty[2]-ty[0]);
        d[2]=sqr(tx[2]-tx[1])+sqr(ty[2]-ty[1]);
        if(d[0]==d[1]+d[2]){
            swap(tx[0],tx[2]);swap(ty[0],ty[2]);
        }else if(d[1]==d[0]+d[2]){
            swap(tx[0],tx[1]);swap(ty[0],ty[1]);
        }
        tx[3]=tx[1]+tx[2]-tx[0];
        ty[3]=ty[1]+ty[2]-ty[0];
        for(int j=0;j<4;j++){
            x[4*i+j]=tx[j];
            y[4*i+j]=ty[j];
        }
        for(int j=0;j<4;j++)//In same city 
            for(int k=j;k<4;k++)
                dis[4*i+k][4*i+j]=dis[4*i+j][4*i+k]=getdis(tx[j],ty[j],tx[k],ty[k])*len;
        for(int j=0;j<i;j++)//in diffirent cities 
            for(int k=0;k<4;k++)
                for(int l=0;l<4;l++)
                    dis[4*i+l][4*j+k]=dis[4*j+k][4*i+l]=getdis(x[4*j+k],y[4*j+k],tx[l],ty[l])*t;
	}
	for(int k=0;k<4*s;k++)//Floyd
        for(int i=0;i<4*s;i++)
            for(int j=i+1;j<4*s;j++)
                dis[j][i]=dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            ans=min(ans,dis[4*a+i][4*b+j]);
    return ans;
}
int main(){
    int n;scanf("%d", &n);
    while(n--)printf("%.1lf\n",solve());
    return 0;
}
