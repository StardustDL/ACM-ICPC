/*
Ants
���⣺����N���׵��N���ڵ㣬Ҫ����N�����ཻ���߶ΰ�������������������ÿ���߶�ǡ������һ���׵��һ���ڵ㣬ÿ����ǡ�����ӵ�һ���߶Ρ����һ�����ӷ�ʽ
��������Ϊ�н��ڰ���ɫ�����ǲ����뵽����һ������ͼ������ÿ���׵��Ӧһ��X��㣬ÿ���ڵ��Ӧһ��Y��㣬
	  ÿ���ڵ��ÿ���׵�������Ȩֵ���ڶ��ߵ�ŷ����¾��롣
	  ��ģ���������ƥ���������Ľ�֮һ��Ϊʲô�أ�
	  �������������ƥ�����������߶�a1-b1��a2-b2�ཻ����ôdist(a1,b1)+dist(a2,b2)һ������dist(a1,b2)+dist(a2,b1),���������������ĳ�a1-b2��a2-b1���ܳ��Ȼ����,����Ѷ���ì�ܡ� 
	  KM�㷨����Ȩֵ�����ģ�����Ҫ������߳ɸ������ɡ�������������ֵ�����Ǹ���ġ�
	  ������ݴ�����N^3�ģ�ά����һ��slack[y]=min{l(x)+l(y)-w(x,y)} 
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
		double t=fabs(lx[x]+ly[y]-w[x][y]);//�ж�������Ƿ��ڵ�ǰ�Ķ���ͼ�� 
		if(t<eps){
			visy[y]=1;
			if(linky[y]==-1||hungary(linky[y])){
				linky[y]=x;
				return true;
			}
		}
		else slack[y]=min(slack[y],t);//ά��slack���� 
	}
	return false;
}
void KM(){
	memset(linky,-1,sizeof(linky));
	memset(ly,0,sizeof(ly));
	for(int i=1;i<=nx;i++){
		lx[i]=-INF;
		for(int j=1;j<=ny;j++)lx[i]=max(lx[i],w[i][j]);//�����l(x)�ĳ�ʼֵ����ʱl(y)=0 
	}
	for(int x=1;x<=nx;x++){//��ÿ�������ƥ�� 
		for(int i=1;i<=ny;i++)slack[i]=INF;//���¼���slack 
		while(1){
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(hungary(x))break;
			double d=INF;
			for(int i=1;i<=ny;i++)if(!visy[i])d=min(d,slack[i]);//�����С�޸�ֵ 
			for(int i=1;i<=nx;i++)if(visx[i])lx[i]-=d;
			for(int i=1;i<=ny;i++)if(visy[i])ly[i]+=d;else slack[i]-=d;//ά������ 
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
	for(int i=1;i<=ny;i++){//�������߿�����linky[i]����Ҫ����Ĵ� 
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

