/*
Ants
题意：给出N个白点和N个黑点，要求用N条不相交的线段把它们连接起来，其中每条线段恰好连接一个白点和一个黑点，每个点恰好连接到一条线段。求出一种连接方式
分析：因为有结点黑白两色，我们不难想到构造一个二分图，其中每个白点对应一个X结点，每个黑点对应一个Y结点，
	  每个黑点和每个白点相连，权值等于二者的欧几里德距离。
	  建模后最佳完美匹配就是问题的解之一。为什么呢？
	  假设在最佳完美匹配中有两条线段a1-b1与a2-b2相交，那么dist(a1,b1)+dist(a2,b2)一定大于dist(a1,b2)+dist(a2,b1),因此如果把这两条改成a1-b2和a2-b1后总长度会变少,与最佳二字矛盾。 
	  KM算法是求权值和最大的，故需要将距离边成负数即可。并且输入坐标值好像是浮点的。
	  下面这份代码是N^3的，维护了一个slack[y]=min{l(x)+l(y)-w(x,y)} 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#define sqr(x) ((x)*(x))
using namespace std;
const double INF=9999999999;
const int MAXN=100;
const double eps=1e-5;
struct point{
	double x,y;
}ant[MAXN+3],apple[MAXN+3];
double w[MAXN+3][MAXN+3],lx[MAXN+3],ly[MAXN+3],slack[MAXN+3];
int linky[MAXN+3];
int nx,ny;
bool visx[MAXN+3],visy[MAXN+3];
bool hungary(int x){
	visx[x]=1;
	for(int y=1;y<=ny;y++){
		if(visy[y])continue;
		double t=fabs(lx[x]+ly[y]-w[x][y]);//判断这个点是否在当前的二分图中 
		if(t<eps){
			visy[y]=1;
			if(linky[y]==-1||hungary(linky[y])){
				linky[y]=x;
				return true;
			}
		}
		else slack[y]=min(slack[y],t);//维护slack数组 
	}
	return false;
}
void KM(){
	memset(linky,-1,sizeof(linky));
	memset(ly,0,sizeof(ly));
	for(int i=1;i<=nx;i++){
		lx[i]=-INF;
		for(int j=1;j<=ny;j++)lx[i]=max(lx[i],w[i][j]);//先求出l(x)的初始值，此时l(y)=0 
	}
	for(int x=1;x<=nx;x++){//对每个点进行匹配 
		for(int i=1;i<=ny;i++)slack[i]=INF;//重新计算slack 
		while(1){
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(hungary(x))break;
			double d=INF;
			for(int i=1;i<=ny;i++)if(!visy[i])d=min(d,slack[i]);//求出最小修改值 
			for(int i=1;i<=nx;i++)if(visx[i])lx[i]-=d;
			for(int i=1;i<=ny;i++)if(visy[i])ly[i]+=d;else slack[i]-=d;//维护顶标 
		}
	}
}
double getd(point &a,point &b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)); 
}
void input(){
	scanf("%d",&nx,&ny);ny=nx;
	for(int i=1;i<=nx;i++)scanf("%lf%lf",&ant[i].x,&ant[i].y);
	for(int i=1;i<=ny;i++)scanf("%lf%lf",&apple[i].x,&apple[i].y);
	for(int i=1;i<=ny;i++){//这样连边可以让linky[i]存着要输出的答案 
		for(int j=1;j<=nx;j++){
			w[i][j]=-getd(apple[i],ant[j]); 
		}
	}
}
int main(){
	input();
	KM();
	for(int i=1;i<=ny;i++)printf("%d\n",linky[i]); 
	return 0;
}

