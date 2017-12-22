/*
[JSOI2007]合金
分析：转化为二维问题，第三维可以由前两维确定，所以可以不用管。
		然后两种原料能配成的产品一定在两个点的线段上。
		转化成在m个点里找最少点，使其完全包含那n个点。
		如果所有目标点在线段a,b的同一侧则dis[a][b]=1
			否则dis[a][b]=inf
		然后跑floyd最小环，答案是min{dis[i][i]}
		重点是特判= = 
		 所有点重合/共线，就是写不对= = 
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#define eps 1e-10
using namespace std;
const int MAXN=500,INF=0x3f3f3f3f; 
struct point{
    double x,y;
}p[MAXN+3],s[MAXN+3];
int n,m,dis[MAXN+3][MAXN+3];
inline int dc(double x){
    if(x>eps) return 1;
    else if(x<-eps) return -1;
    return 0;
}
inline double cross(const point &a,const point &b,const point &c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
inline double dot(const point &a,const point &b,const point &c){
    return (b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
}
bool check(const point &a,const point &b){
    for(int i=1;i<=n;i++)
        if(dc(cross(a,b,s[i]))<0) return false;
    return true;
}
bool onpoint(){
    for(int i=1;i<=m;i++){
        int cnt=0;
        for(int j=1;j<=n;j++)
            if(dc(p[i].x-s[j].x)==0&&dc(p[i].y-s[j].y)==0) cnt++;
            else break;
        if(cnt==n) return true;
    }
    return false;
}
bool onseg(){//如果所有点共线,且没有一条线段包含他们所有点，则返回真 
    for(int i=3;i<=n;i++)
        if(dc(cross(s[1],s[2],s[i]))!=0) return false;
    for(int i=1;i<=m;i++)
        for(int j=i+1;j<=m;j++){
            int cnt=0;
            for(int k=1;k<=n;k++)
                if(dc(dot(s[k],p[i],p[j]))<=0)cnt++;//为什么<=0就包含了呢 
            if(cnt==n) return false;
        }
    return true;
}
int main(){
    scanf("%d%d",&m,&n);
    double tmp;
    for(int i=1;i<=m;i++)
        scanf("%lf%lf%lf",&p[i].x,&p[i].y,&tmp);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf%lf",&s[i].x,&s[i].y,&tmp);
        
    if(n==0) {puts("0");return 0;}
    if(onpoint()) {puts("1");return 0;}
    if(onseg()) {puts("-1");return 0;}
    
    int ans=INF;
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++){
            if(i==j) continue;
            if(check(p[i],p[j])) dis[i][j]=1;
        }
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            if(dis[i][k]<INF)
                for(int j=1;j<=m;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=m;i++) ans=min(ans,dis[i][i]);
    if(ans==INF) ans=-1;
    printf("%d\n",ans);
    return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath> 
#define sqr(x) ((x)*(x))
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
struct point{
	double x,y;
}pm[MAXN+3],pn[MAXN+3];
int dcmp(double d){return fabs(d)<1e-10?0:(d>0?1:-1);}
int mp[MAXN+3][MAXN+3],n,m;
double cross(point a,point b,point c){
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
double dot(point a,point b,point c){
	return (a.x-c.x)*(b.x-c.x)+(a.y-c.y)*(b.y-c.y);
}
double dist(point a,point b){
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
bool check(point a,point b){
	for(int i=1;i<=n;i++){
		if(dcmp(cross(a,b,pn[i]))<0)return false;
	}
	return true;
}
void build(){
	memset(mp,INF,sizeof(mp));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			if(check(pm[i],pm[j]))mp[i][j]=1;
		}
	}
}
bool spj(){
	if(n==0){puts("0");return true;}
	bool op=true;
	for(int i=2;i<=n;i++)if(dcmp(pn[i].x-pn[1].x)!=0||dcmp(pn[i].y-pn[1].y)!=0){op=false;break;}
	if(op){
		for(int i=1;i<=m;i++){
			if(dcmp(pm[i].x-pn[1].x)==0&&dcmp(pm[i].y-pn[1].y)==0){
				puts("1");
				return true;
			}
		}
		puts("-1");
		return true;
	}
	op=true;
	for(int i=3;i<=n;i++)
        if(dcmp(cross(pn[i],pn[i-1],pn[1]))!=0){op=false;break;}
    if(op){
    	//cout<<"QQ"<<endl;
    	int flg=0;
		for(int i=1;i<=m;i++)
        	for(int j=i+1;j<=m;j++)
        	{
        		int cnt=0;
            	for(int k=1;k<=n;k++)
            	    if(dcmp(dot(pm[i],pm[j],pn[k]))<=0) cnt++;
            	if(cnt==n)return false;
        		------------------//
				flg=0;
        		double di=dist(pm[i],pm[j]);
            	for(int k=1;k<=n;k++){
            		double d=dot(pn[k],pm[j],pm[i]),y=dist(pn[k],pm[i]);
            		double t=d/di/y;
            		if(dcmp(fabs(t)-1.0)!=0){flg=1;break;}//pn[k]不在直线ij上
					if(dcmp(t)<0) {flg=-1;break;}//pn[k]不在线段ij上 
					if(dcmp(t)>0 && dcmp(y-di)>0) {flg=-1;break;}
				}
				//cout<<flg<<endl;
            	if(flg==-1)continue;
            	if(flg==1){return false;}
				else {puts("2");return true;}
				------------------
        	}
        puts("-1");//说明没有线段可以覆盖所有点 
        return true;
	}
	return false;
	//op=true;
	//for(int i=2;i<=n;i++)if(dcmp(pn[i].x-pn[1].x)!=0||dcmp(pn[i].y-pn[1].y)!=0){op=false;break;}
}
int main(){
	scanf("%d%d",&m,&n);
    double tmp;
    for(int i=1;i<=m;i++)
        scanf("%lf%lf%lf",&pm[i].x,&pm[i].y,&tmp);
    for(int i=1;i<=n;i++)
        scanf("%lf%lf%lf",&pn[i].x,&pn[i].y,&tmp);
    if(spj())return 0;
    //cout<<"!!"<<endl;
    build();
    int ans=INF;
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            if(mp[i][k]<INF)
                for(int j=1;j<=m;j++)
                    mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
    for(int i=1;i<=m;i++)ans=min(ans,mp[i][i]);
    if(ans==INF)ans=-1;
    printf("%d\n",ans);
	return 0;
}
*/
