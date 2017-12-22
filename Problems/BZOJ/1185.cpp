/*
[HNOI2007]最小矩形覆盖
分析：结论：矩形一边一定与凸包上的一边重合
		枚举凸包上的边，旋转卡壳得到另外三个点
	  练习好题。	 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
const double eps=1e-8;
#define sqr(x) ((x)*(x))
int n,top;
double ans=1e60;
int dc(double t){
	return fabs(t)<eps?0:(t>0?1:-1);
}
struct P{
	double x,y;
	P(){}P(double x,double y):x(x),y(y){}
	friend bool operator <(P a,P b){
		return dc(a.y-b.y)==0?a.x<b.x:a.y<b.y;
	}
	friend P operator +(P a,P b){return P(a.x+b.x,a.y+b.y);}
	friend P operator -(P a,P b){return P(a.x-b.x,a.y-b.y);}
	friend P operator *(P a,double d){return P(a.x*d,a.y*d);}
	friend double operator *(P a,P b){return a.x*b.y-b.x*a.y;}
	friend double operator /(P a,P b){return a.x*b.x+b.y*a.y;}
	friend double dist(P a){
		return sqrt(sqr(a.x)+sqr(a.y));
	}
}p[MAXN+3],q[MAXN+3],t[5];
bool cmp(P a,P b){//按极角从小到大排序 
	double t=(a-p[1])*(b-p[1]);
	if(dc(t)==0)return dc(dist(a)-dist(b))<0;
	return t>0; 
}
void graham(){
	for(int i=2;i<=n;i++)if(p[i]<p[1])swap(p[1],p[i]);//找到y,x最小的
	sort(p+2,p+n+1,cmp);
	q[++top]=p[1];
	for(int i=2;i<=n;i++){
		while(top>1&&(q[top]-q[top-1])*(p[i]-q[top])<eps)top--;//保持边是逆时针转的
		q[++top]=p[i]; 
	}
	q[0]=q[top];
}
void RC(){
	int l=1,r=1,p=1;
	double D,L,R,H;
	for(int i=0;i<top;i++){
		P pt=q[i+1]-q[i];
		D=dist(pt);
		while(pt*(q[p+1]-q[i])-pt*(q[p]-q[i])>-eps)p=(p+1)%top;//根据高找对顶点 
		while(pt/(q[r+1]-q[i])-pt/(q[r]-q[i])>-eps)r=(r+1)%top;//根据边的投影找两侧的最远点 
		if(i==0)l=r;
		while(pt/(q[l+1]-q[i])-pt/(q[l]-q[i])<eps)l=(l+1)%top;
		L=pt/(q[l]-q[i])/D,R=pt/(q[r]-q[i])/D;
		H=fabs(pt*(q[p]-q[i])/D);//对顶点的高 
		double tmp=(R-L)*H;
		if(tmp<ans){
			ans=tmp;//向量加减，求出四个点 
			t[0]=q[i]+(q[i+1]-q[i])*(R/D);
			t[1]=t[0]+(q[r]-t[0])*(H/dist(q[r]-t[0]));
			t[2]=t[1]+(q[i]-t[0])*((R-L)/dist(q[i]-t[0]));
			t[3]=t[2]+(t[0]-t[1]);
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lf%lf",&p[i].x,&p[i].y);
	graham();RC();
	printf("%.5lf\n",ans);
	int sta=0;for(int i=1;i<=3;i++)if(t[i]<t[sta])sta=i;
	for(int i=0;i<=3;i++)printf("%.5lf %.5lf\n",t[(i+sta)%4].x,t[(i+sta)%4].y);
	return 0;
}

